module Main where

import System.Environment
import Data.List

addElemFirst :: [a] -> [a] -> [a]
addElemFirst (x:xs) (y:_) = (y:x:xs)
addElemFirst [] (y:_) = [y]
addElemFirst x [] = x

delFirstElem :: [a] -> [a]
delFirstElem [] = []
delFirstElem (_:xs) = xs

swapFirstElem :: [a] -> [a]
swapFirstElem [] = []
swapFirstElem (a:b:c) = (b:a:c)
swapFirstElem (a) = (a)

headEnd :: [a] -> [a]
headEnd [] = []
headEnd (x:xs) = xs ++ [x]

endHead :: [a] -> [a]
endHead [] = []
endHead (x:xs) = last xs : init (x:xs)

pushSwap :: [[Char]] -> [a] -> [a] -> ([a], [a])
pushSwap [] l_a l_b = (l_a, l_b)
pushSwap (x:xs) (l_a) (l_b)
    | isSubsequenceOf x "sa" == True = pushSwap xs (swapFirstElem l_a) l_b
    | isSubsequenceOf x "sb" == True = pushSwap xs l_a (swapFirstElem l_b)
    | isSubsequenceOf x "sc" == True = pushSwap xs (swapFirstElem l_a) (swapFirstElem l_b)
    | isSubsequenceOf x "pa" == True = pushSwap xs (addElemFirst l_a l_b) (delFirstElem l_b)
    | isSubsequenceOf x "pb" == True = pushSwap xs (delFirstElem l_a) (addElemFirst l_b l_a) 
    | isSubsequenceOf x "ra" == True = pushSwap xs (headEnd l_a) l_b
    | isSubsequenceOf x "rb" == True = pushSwap xs l_a (headEnd l_b)
    | isSubsequenceOf x "rr" == True = pushSwap xs (headEnd l_a) (headEnd l_b)
    | isSubsequenceOf x "rra" == True = pushSwap xs (endHead l_a) l_b
    | isSubsequenceOf x "rrb" == True = pushSwap xs l_a (endHead l_b)
    | isSubsequenceOf x "rrr" == True = pushSwap xs (endHead l_a) (endHead l_b)
    | otherwise = error "Error: Command not found"

myTransform :: [String] -> [Int]
myTransform [] = []
myTransform (x:xs) = do
    case reads x :: [(Int, String)] of
        [(value, _)] -> value : myTransform xs
        _ -> []

myPrint' :: [String] -> IO ()
myPrint' str = do
    putStr "KO: "
    print (myTransform str)

myPrint :: ([String], [String]) -> IO ()
myPrint (l_a, []) = myPrint' l_a
myPrint ([], l_b) = myPrint' l_b
myPrint (l_a, l_b) = do
    putStr "KO: "
    print ((myTransform l_a), (myTransform l_b))


readInt :: [String] -> Bool
readInt [] = True
readInt (x:xs)  = do
    case reads x :: [(Int,String)] of
        [(_, _)] -> readInt xs
        _ -> False

myAlgo :: String -> [String] -> IO ()
myAlgo string args = do
    let (l_a, l_b) = pushSwap (words string) args []
    let result = sort args
    if result == l_a then putStr "OK\n" else myPrint (l_a, l_b)

myError :: a
myError = error "Error: Invalid argument, only number are autorized"

main :: IO ()
main = do
    string <- getLine
    args <- getArgs
    print args
    if (readInt args) == False then myError else myAlgo string args