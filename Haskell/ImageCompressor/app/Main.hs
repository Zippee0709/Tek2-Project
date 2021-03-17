module Main where
import Prelude
import System.Environment
import System.Exit
import Data.Char
import Data.List
import Data.Typeable()
import System.IO
import System.Random
import System.Directory
import Text.Read
import Control.Monad

type Color = (Int, Int, Int)
type Point = (Int, Int)

myTriplet :: a -> b -> c -> (a, b, c)
myTriplet a b c = (a, b ,c)

triplet1 :: (a, b, c) -> a
triplet1 (a, b, c) = a

triplet2 :: (a, b, c) -> b
triplet2 (a, b, c) = b

triplet3 :: (a, b, c) -> c
triplet3 (a, b, c) = c

myTuple ::  a -> b -> (a, b)
myTuple a b = (a, b)

checkCluster :: String -> Int
checkCluster n = read n :: Int

checkLimit :: String -> Float
checkLimit e = read e :: Float

getTuple :: String -> String -> String -> Int -> (Int, Int)
getTuple (x:xs) a b s
    | x == '(' = getTuple xs a b s
    | x == ',' = getTuple xs a b (s + 1)
    | x == ')' = myTuple (checkCluster a) (checkCluster b)
    | s == 0 = getTuple xs (a ++ [x]) b s
    | s == 1 = getTuple xs a (b ++ [x]) s

getTriplet :: String -> String -> String -> String -> Int -> (Int, Int, Int)
getTriplet (x:xs) a b c s
    | x == '(' = getTriplet xs a b c s
    | x == ',' = getTriplet xs a b c (s + 1)
    | x == ')' = myTriplet (checkCluster a) (checkCluster b) (checkCluster c)
    | s == 0 = getTriplet xs (a ++ [x]) b c s
    | s == 1 = getTriplet xs a (b ++ [x]) c s
    | s == 2 = getTriplet xs a b (c ++ [x]) s

transformeTupleStringToTupleInt :: [(String, String)] -> [((Int, Int), (Int, Int, Int))] -> [((Int, Int), (Int, Int, Int))]
transformeTupleStringToTupleInt [] list = list
transformeTupleStringToTupleInt (x:xs) list = transformeTupleStringToTupleInt xs (list ++ [myTuple (getTuple (fst x) "" "" 0) (getTriplet (snd x) "" "" "" 0)])

stringToTupleString :: [String] -> (String, String)
stringToTupleString (a:b:xs) = myTuple a b

formatterString :: [String] -> [(String, String)] -> [(String, String)]
formatterString [] list = list
formatterString (x:xs) list = formatterString xs (list ++ [stringToTupleString (words x)])

-- Début RANDOM 0 à 255

-- myRand :: StdGen -> Int -> [Int] -> [Int]
-- myRand _ 0 list = list
-- myRand gen start list = do
--     let (randNb, newGen) = randomR (0, 255) gen :: (Int, StdGen)
--     myRand newGen (start - 1) (list ++ [randNb])

-- parseRand :: [Int] -> [(Int, Int, Int)] -> Int -> [(Int, Int, Int)]
-- parseRand _ list 0 = list
-- parseRand (a:b:c:xs) list len = parseRand xs (list ++ [myTriplet a b c]) (len - 3)

-- initialisationMeans n = do
--     g <- getStdGen
--     let nb = myRand g (n * 3) []
--     let means = parseRand nb [] (length nb)
--     return means

-- FIN RANDOM 0 à 255

-- Début RANDOM points in file

myRand :: StdGen -> Int -> [Int] -> Int -> [Int]
myRand _ 0 list _ = list
myRand gen start list len = do
    let (randNb, newGen) = randomR (0, len - 1) gen :: (Int, StdGen)
    myRand newGen (start - 1) (list ++ [randNb]) len

parseRand :: [Int] -> [(Int, Int, Int)] -> [((Int, Int), (Int, Int, Int))] -> [(Int, Int, Int)]
parseRand [] list _ = list
parseRand (x:xs) list points = parseRand xs (list ++ [snd (points!!x)]) points

initialisationMeans n points = do
    g <- getStdGen
    let nb = myRand g n [] (length points)
    let means = parseRand nb [] points
    return means

-- Début RANDOM points in file

kMeans :: Float -> Float -> Float -> Float -> Float -> Float -> Float
kMeans r1 g1 b1 r2 g2 b2 = sqrt (((r1 - r2)^2) + ((g1 - g2)^2) + ((b1 - b2)^2))

replaceMean :: Int -> [(Int, Int, Int)] -> (Int, Int, Int) -> [(Int, Int, Int)]
replaceMean n (x:xs) value
    | n == 0 = value:xs
    | otherwise = x:replaceMean (n-1) xs value

initMeanWithZero :: Int -> [(Int, Int, Int)] -> [(Int, Int, Int)]
initMeanWithZero 0 list = list
initMeanWithZero n list = initMeanWithZero (n - 1) (list ++ [(0, 0, 0)])

calcDistance :: ((Int, Int), (Int, Int, Int)) -> [(Int, Int, Int)] -> [Float] -> Float -> [Float]
calcDistance _ [] list _ = list
calcDistance pts (y:ys) list conv
    | null (y:ys) = list
    | res < conv = calcDistance pts ys (list ++ [res]) res
    | otherwise = calcDistance pts ys (list ++ [res]) conv
    where x = snd pts
          r1 = triplet1 x
          g1 = triplet2 x
          b1 = triplet3 x
          r2 = triplet1 y
          g2 = triplet2 y
          b2 = triplet3 y
          res = kMeans (intToFloat r1) (intToFloat g1) (intToFloat b1) (intToFloat r2) (intToFloat g2) (intToFloat b2)

getPosOfMinValue :: [Float] -> Float -> Int -> Int
getPosOfMinValue (x:xs) min pos
    | x == min = pos
    | otherwise = getPosOfMinValue xs min (pos + 1)

algo :: [((Int, Int), (Int, Int, Int))] -> [(Int, Int, Int)] -> [Int] -> [Int]
algo [] _ ident = ident
algo (pts:ptxs) means ident = algo ptxs means (ident ++ [getPosOfMinValue (calcDistance pts means [] 1000) (minimum (calcDistance pts means [] 1000)) 0])

checkZeroInMean :: [(Int, Int, Int)] -> Bool
checkZeroInMean [] = False
checkZeroInMean (x:xs)
    | a == 0 && b == 0 && c == 0 = True
    | otherwise = checkZeroInMean xs
    where a = triplet1 x
          b = triplet2 x
          c = triplet3 x

-- addMean :: ((Int, Int), (Int, Int, Int)) -> Int -> [(Int, Int, Int)] -> [(Int, Int, Int)]
-- addMean pts ident mean
--     | checkZeroInMean m = replaceMean ident mean (myTriplet (r1 + r2) (g1 + g2) (b1 + b2))
--     | otherwise = replaceMean ident mean (myTriplet (div (r1 + r2) 2) (div (g1 + g2) 2) (div (b1 + b2) 2))
--     where m = mean!!ident
--           p = snd pts
--           r1 = triplet1 p
--           g1 = triplet2 p
--           b1 = triplet3 p
--           r2 = triplet1 m
--           g2 = triplet2 m
--           b2 = triplet3 m

-- addMean :: ((Int, Int), (Int, Int, Int)) -> Int -> [(Int, Int, Int)] -> [(Int, Int, Int)]
-- addMean pts ident mean = replaceMean ident mean (myTriplet (triplet1 (snd pts) + triplet1 (mean!!ident)) (triplet2 (snd pts) + triplet2 (mean!!ident)) (triplet3 (snd pts) + triplet3 (mean!!ident)))

addMean :: ((Int, Int), (Int, Int, Int)) -> Int -> [(Int, Int, Int)] -> [(Int, Int, Int)]
addMean pts ident mean = replaceMean ident mean (myTriplet (r1 + r2) (g1 + g2) (b1 + b2))
    where m = mean!!ident
          p = snd pts
          r1 = triplet1 p
          g1 = triplet2 p
          b1 = triplet3 p
          r2 = triplet1 m
          g2 = triplet2 m
          b2 = triplet3 m

countElems :: Int -> [Int] -> Int
countElems _ []     = 0
countElems n (x:xs) = fromEnum (n == x) + countElems n xs

divideMean :: [Int] -> [(Int, Int, Int)] -> Int -> Int -> [(Int, Int, Int)]
divideMean ident mean start n
    | start < n && nb /= 0 = divideMean ident (replaceMean start mean (myTriplet (div r1 nb) (div g1 nb) (div b1 nb))) (start + 1) n
    | start < n && nb == 0 = divideMean ident mean (start + 1) n
    | start == n = mean
    where m = mean!!start
          (r1, g1, b1) = m
          nb = countElems start ident

intToFloat :: Int -> Float
intToFloat n = fromInteger (toInteger n)

calcNewMean :: [((Int, Int), (Int, Int, Int))] -> [Int] -> [(Int, Int, Int)] -> [(Int, Int, Int)]
calcNewMean [] ident mean = mean
calcNewMean (pts:ptxs) (ident:identxs) mean = calcNewMean ptxs identxs (addMean pts ident mean)

-- checkConvergence :: [(Int, Int, Int)] -> [(Int, Int, Int)] -> Float -> Int -> Int
checkConvergence :: [Color] -> [Color] -> Float -> Int -> Int
checkConvergence [] _ _ nb = nb
checkConvergence _ [] _ nb = nb
checkConvergence (x:xs) (y:ys) e nb
    | convergence < e = checkConvergence xs ys e (nb + 1)
    | otherwise = checkConvergence xs ys e nb
    where (r1, g1, b1) = x
          (r2, g2, b2) = y
          convergence = kMeans (intToFloat r1) (intToFloat g1) (intToFloat b1) (intToFloat r2) (intToFloat g2) (intToFloat b2)

printPts :: [((Int, Int), (Int, Int, Int))] -> IO ()
printPts [] = return ()
printPts (x:xs) = do
    putStrLn (show (fst x) ++ " " ++ show (snd x))
    printPts xs

associatePts :: [((Int, Int), (Int, Int, Int))] -> [Int] -> Int -> [((Int, Int), (Int, Int, Int))] -> [((Int, Int), (Int, Int, Int))]
associatePts [] _ _ list = list
associatePts (pts:ptxs) (ident:identxs) start list
    | ident == start = associatePts ptxs identxs start (list ++ [pts])
    | otherwise = associatePts ptxs identxs start list

printOutput :: [((Int, Int), (Int, Int, Int))] -> [(Int, Int, Int)] -> [Int] -> Int -> IO ()
printOutput _ [] _ _ = return ()
printOutput points (mean:meanxs) ident start = do
    putStrLn "--"
    print mean
    putStrLn "-"
    let associate = associatePts points ident start []
    printPts associate
    if null (mean:meanxs) then return () else printOutput points meanxs ident (start + 1)

addLastMean :: [(Int, Int, Int)] -> [(Int, Int, Int)] -> [(Int, Int, Int)] -> Int -> [(Int, Int, Int)]
addLastMean [] [] newMeans _ = newMeans
addLastMean (x:xs) (y:ys) newMeans start
    | a == 0 && b == 0 && c == 0 = addLastMean xs ys (replaceMean start newMeans y) (start + 1)
    | otherwise = addLastMean xs ys newMeans (start + 1)
    where a = triplet1 x
          b = triplet2 x
          c = triplet3 x

checkNewMeans :: [(Int, Int, Int)] -> [(Int, Int, Int)] -> [(Int, Int, Int)] -> Int -> [(Int, Int, Int)]
checkNewMeans new last newMeans start
    | checkZeroInMean newMeans = addLastMean new last newMeans 0
    | otherwise = newMeans

startAlgo :: [((Int, Int), (Int, Int, Int))] -> [(Int, Int, Int)] -> Int -> Float -> IO ()
startAlgo points means n e =
    let ident = algo points means []
        tmp = divideMean ident (calcNewMean points ident (initMeanWithZero n [])) 0 n
        newMeans = checkNewMeans tmp means tmp 0
    in if checkConvergence means newMeans e 0 == length newMeans
        then printOutput points newMeans ident 0
        else startAlgo points newMeans n e
    
myKmeans n e contents = do
    let points = transformeTupleStringToTupleInt (formatterString (lines contents) []) []
    means <- initialisationMeans n points
    startAlgo points means n e

checkFile n e file = do
    contents <- readFile file
    if length contents <= 15 then exitWithErrorMsg "Error : the given file is empty" 84 else myKmeans n e contents

readColor n e file = do
    error <- doesFileExist file
    if error then checkFile n e file else exitWithErrorMsg "Error : the given file doesn't exist" 84

checkParam n e file = case n of 
        Nothing -> exitWithErrorMsg "Error : the first argument need to be an Int" 84
        Just n -> case e of
            Nothing -> exitWithErrorMsg "Error : the second argument need to be an Float" 84
            Just e -> readColor n e file

parseParam (n:e:file:xs) = checkParam (readMaybe n :: Maybe Int) (readMaybe e :: Maybe Float) file

usage :: IO()
usage = putStrLn "Usage\n\t./imageCompressor n e IN\n\n\
                  \\tn\tnumber of colors in the final image\n\
                  \\te\tconvergence limit\n\
                  \\tIN\tpath to the file containing the colors of the pixels"

parseAv :: [String] -> IO()
parseAv [] = exitWithErrorMsg "Error: invalid argument" 84
parseAv ["-h"] = usage
parseAv arg = if length arg == 3 then parseParam arg else exitWithErrorMsg "Error : invalid argument, the number of argument need be 3" 84

exitWithErrorMsg :: String -> Int -> IO()
exitWithErrorMsg str e = putStrLn str >> exitWith (ExitFailure e)

main :: IO()
main = getArgs >>= parseAv
