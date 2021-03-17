module Main where
import System.Environment
import System.Exit

myTriplet :: a -> b -> c -> (a, b, c)
myTriplet a b c = (a, b ,c)

myTuple ::  a -> b -> (a, b)
myTuple a b = (a, b)

changeValue :: Int -> [(a, b)] -> (a, b) -> [(a, b)]
changeValue _ [] _ = []
changeValue n (param: paramxs) (a, b)
    | n == 0 = (a, b):paramxs
    | otherwise = param:changeValue (n-1) paramxs (a, b)

replaceValue :: Int -> [Int] -> Int -> [Int]
replaceValue _ [] _ = []
replaceValue n (param: paramxs) x
    | n == 0 = x:paramxs
    | otherwise = param:replaceValue (n-1) paramxs x
    
changeParam :: [(String, String)] -> [String] -> [(String, String)] 
changeParam [] _ = error "Error : Default parameter no given in changeParam"
changeParam (_:_) [_] = error "Error : Parameter is null in changeParam"
changeParam (param : paramxs) [] = param : paramxs
changeParam (param : paramxs) (av : avs : avxs)
    | av == "--rule" = changeParam (changeValue 0 (param:paramxs) (myTuple av avs)) avxs
    | av == "--start" = changeParam (changeValue 1 (param:paramxs) (myTuple av avs)) avxs
    | av == "--lines" = changeParam (changeValue 2 (param:paramxs) (myTuple av avs)) avxs
    | av == "--window" = changeParam (changeValue 3 (param:paramxs) (myTuple av avs)) avxs
    | av == "--move" = changeParam (changeValue 4 (param:paramxs) $ myTuple av avs) avxs
    | otherwise = error "Error : Invalid parameter given"

parseParam :: [String] -> [(String, String)]
parseParam [] = error "Error : Invalid input"
parseParam (av:avxs) = changeParam (zip ["--rule", "--start", "--lines", "--window", "--move"] ["0", "0", "-1", "80", "0"]) (av:avxs)

calcRule30 :: Char -> Char -> Char -> Char
calcRule30 '1' '1' '1' = '0'
calcRule30 a b c
    | a == '1' && b == '1' && c == '1' = '0'
    | a == '0' && b == '0' && c == '0' = '0'
    | a == '1' && b == '0' && c == '1' = '0'
    | a == '1' && b == '1' && c == '0' = '0'
    | a == '0' && b == '0' && c == '1' = '1'
    | a == '0' && b == '1' && c == '0' = '1'
    | a == '0' && b == '1' && c == '1' = '1'
    | a == '1' && b == '0' && c == '0' = '1'
    | otherwise = error "Error : Invalid parsing from calc30"

calcRule90 :: Char -> Char -> Char -> Char
calcRule90 a b c
    | a == '1' && b == '1' && c == '1' = '0'
    | a == '0' && b == '0' && c == '0' = '0'
    | a == '1' && b == '0' && c == '1' = '0'
    | a == '0' && b == '1' && c == '0' = '0'
    | a == '1' && b == '1' && c == '0' = '1'
    | a == '0' && b == '0' && c == '1' = '1'
    | a == '0' && b == '1' && c == '1' = '1'
    | a == '1' && b == '0' && c == '0' = '1'
    | otherwise = error "Error : Invalid parsing from calc90"

calcRule110 :: Char -> Char -> Char -> Char
calcRule110 a b c
    | a == '1' && b == '1' && c == '1' = '0'
    | a == '0' && b == '0' && c == '0' = '0'
    | a == '1' && b == '0' && c == '0' = '0'
    | a == '1' && b == '0' && c == '1' = '1'
    | a == '0' && b == '1' && c == '0' = '1'
    | a == '1' && b == '1' && c == '0' = '1'
    | a == '0' && b == '0' && c == '1' = '1'
    | a == '0' && b == '1' && c == '1' = '1'
    | otherwise = error "Error : Invalid parsing from calc110"
    
genCellular30 :: String -> String -> String
genCellular30 [] newGen = newGen
genCellular30 [_] newGen = newGen
genCellular30 [_, _] newGen = reverse (['0', '0'] ++ newGen ++ ['0', '0'])
genCellular30 (xa:xb:xc:xss) newGen
    | abc == '1' = genCellular30 (xb:xc:xss) (abc:newGen)
    | otherwise = genCellular30 (xb:xc:xss) ('0':newGen)
    where abc = calcRule30 xa xb xc

genCellular90 :: String -> String -> String
genCellular90 [] newGen = newGen
genCellular90 [_] newGen = newGen
genCellular90 [_, _] newGen = reverse (['0', '0'] ++ newGen ++ ['0', '0'])
genCellular90 (xa:xb:xc:xss) newGen
    | abc == '1' = genCellular90 (xb:xc:xss) (abc:newGen)
    | otherwise = genCellular90 (xb:xc:xss) ('0':newGen)
    where abc = calcRule90 xa xb xc 

genCellular110 :: String -> String -> String
genCellular110 [] newGen = newGen
genCellular110 [_] newGen = newGen
genCellular110 [_, _] newGen = reverse (['0', '0'] ++ newGen ++ ['0', '0'])
genCellular110 (xa:xb:xc:xss) newGen
    | abc == '1' = genCellular110 (xb:xc:xss) (abc:newGen)
    | otherwise = genCellular110 (xb:xc:xss) ('0':newGen)
    where abc = calcRule110 xa xb xc
    
calcNbofLeftSpace :: Int -> Int -> Int
calcNbofLeftSpace win len = div (win - len) 2 + 1

myAddNbSpace :: Int -> Int -> String -> String
myAddNbSpace 0 0 str = str
myAddNbSpace left right str
    | left < 0 = myAddNbSpace (left + 1) right (tail str)
    | right < 0 = myAddNbSpace left (right + 1) (init str)
    | left > 0 && right == 0 = myAddNbSpace (left - 1) right (' ':str)
    | left == 0 && right > 0 = myAddNbSpace left (right - 1) (str ++ [' '])
    | otherwise = myAddNbSpace (left - 1) (right - 1) (' ':str ++ [' '])

myFilterLeft :: String -> Int -> String
myFilterLeft [] _ = []
myFilterLeft (x:xs) nb
    | x == '0' && nb > 0 = myFilterLeft xs (nb - 1)
    | otherwise = x:xs

myFilterRight :: String -> Int -> String
myFilterRight [] _ = []
myFilterRight str nb
    | last str == '0' && nb > 0 = myFilterRight (init str) (nb - 1)
    | otherwise = str

myFilterStr :: String -> Int -> String
myFilterStr [] _ = []
myFilterStr str nb = myFilterRight (myFilterLeft str nb) nb

myDelLeft :: String -> Int -> String
myDelLeft [] _ = []
myDelLeft (x:xs) nb
    | nb == 0 = x:xs
    | nb > 0 = myDelLeft xs (nb - 1)
    | otherwise = myDelLeft xs (nb + 1)

myDelRight :: String -> Int -> String
myDelRight [] _ = []
myDelRight str nb
    | nb == 0 = str
    | nb > 0 = myDelLeft (init str) (nb - 1)
    | otherwise = myDelLeft (init str) (nb + 1)

myDelStr :: String -> Int -> Int -> String
myDelStr str left right = myDelRight (myDelLeft str left) right

myMove :: String -> Int -> Int -> String
myMove str left right
    | left < 0 && right < 0 = myDelStr str left right
    | left < 0 = myDelLeft str left
    | otherwise = myDelRight str right

myPrint :: String -> Int -> Int -> IO()
myPrint tab n move = do
    let tmp = myFilterStr tab 2
    let left = calcNbofLeftSpace n (length tmp) + move
    let right = n - length tmp - left
    putStrLn (myAddNbSpace left right (map (\a -> if a == '0' then ' ' else '*') tmp))

rule30 :: String -> Int -> Int -> Int -> Int -> IO()
rule30 tab line win move start = do
    let tmp = genCellular30 tab ""
    if start > 0 then rule30 tmp line win move (start - 1) else myPrint tab win move
    if (line - 1) == 0 then return () else rule30 tmp (line - 1) win move start

rule90 :: String -> Int -> Int ->  Int -> Int-> IO()
rule90 tab line win move start = do
    let tmp = genCellular90 tab ""
    if start > 0 then rule90 tmp line win move (start - 1) else myPrint tab win move
    if (line - 1) == 0 then exitSuccess else rule90 tmp (line - 1) win move start

rule110 :: String -> Int -> Int -> Int -> Int -> IO()
rule110 tab line win move start =
    let tmp = genCellular110 tab "" 
    in do 
        print tab
        if start > 0 then rule110 tmp line win move (start - 1) else myPrint tab win move
        if (line - 1) == 0 then exitSuccess else rule110 tmp (line - 1) win move start
    
myGetNb :: String -> Int
myGetNb [] = 0
myGetNb str = read str :: Int
    
getSpecificParam :: String -> [(String, String)] -> Int
getSpecificParam _ [] = error "Error : Parameter doesn't exist"
getSpecificParam param (x:xs)
    | param == value = myGetNb (snd x)
    | otherwise = getSpecificParam param xs
    where value = fst x

checkParam :: [(String, String)] -> IO ()
checkParam [] = exitWithErrorMsg "Error : Check Parameter" 84
checkParam params@(param:paramxs)
    | ruleValue == "30" = rule30 "00100" (getSpecificParam "--lines" params) (getSpecificParam "--window" params) (getSpecificParam "--move" params) (getSpecificParam "--start" params)
    | ruleValue == "90" = rule90 "00100" (getSpecificParam "--lines" params) (getSpecificParam "--window" params) (getSpecificParam "--move" params) (getSpecificParam "--start" params)
    | ruleValue == "110" = rule110 "00100" myLine myWindow myMove myStart
    | otherwise = exitWithErrorMsg "Error : invalid rules" 84
    where ruleValue = snd param
          myLine = getSpecificParam "--lines" params
          myWindow = getSpecificParam "--window" params
          myMove = getSpecificParam "--move" params
          myStart = getSpecificParam "--start" params

usage :: IO()
usage = putStrLn "Usage\n\
                    \\t./wolfram -- value [param value ...]\n\n\
                    \\t--rule\t\tThe ruleset to use (no default value, mandatory)\n\
                    \\t--start\t\tThe generation number at which to start the display. The default value is 0.\n\
                    \\t--lines\t\tThe number of lines to display. When homited, the program never stops.\n\
                    \\t--window\tThe number of cells to display on each line (line width). If even, \n\
                    \\t\t\tthe central cell is display in the next cell on the right. The default value is 80.\n\
                    \\t--move\t\tA translation to apply on the window. If negative, the window is translated to the left. \n\
                    \\t\t\tIf positive, it’s translated to the right.\n"
    
parseAv:: [String] -> IO()
parseAv [] = exitWithErrorMsg "Error : invalid argument" 84
parseAv ["-h"] = usage
parseAv av =  checkParam (parseParam av)

exitWithErrorMsg :: String -> Int -> IO a
exitWithErrorMsg str e = putStrLn str >> exitWith (ExitFailure e)

main :: IO()
main = getArgs >>= parseAv
