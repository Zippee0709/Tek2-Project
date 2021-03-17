--module DoOp (myElem, safeDiv, safeNth, safeSucc, myLookup, maybeDo, readInt, getLineLength, printAndGetLength, printBox) where

myElem :: Eq a => a -> [a] -> Bool
myElem arg [] = False
myElem arg (x:xs)
    | arg == x = True
    | arg /= x = myElem arg xs

safeDiv :: Int -> Int -> Maybe Int
safeDiv x 0 = Nothing
safeDiv x y = Just (x `div` y)

safeNth :: [a] -> Int -> Maybe a
safeNth [] n = Nothing
safeNth (x:xs) n
    | n < 0 = Nothing
    | n > length (x:xs) = Nothing
safeNth (x:xs) n
    | n == 0 = Just x
    | n /= 0 = safeNth xs (n - 1)

safeSucc :: Maybe Int -> Maybe Int
safeSucc Nothing = Nothing
safeSucc (Just x) = Just (x + 1)

myLookup :: Eq a => a -> [(a, b)] -> Maybe b
myLookup _ [] = Nothing
myLookup n (x:xs)
    | fst x == n = Just (snd (x))
    | fst x /= n = myLookup n xs

maybeDo :: (a -> b -> c) -> Maybe a -> Maybe b -> Maybe c
maybeDo func _ Nothing = Nothing
maybeDo func Nothing _ = Nothing
maybeDo func (Just x) (Just y) = Just (func x y)

readInt :: [Char] -> Maybe Int
readInt str = case reads str of
    [(value, "")] -> Just value
    _ -> Nothing

getInt :: IO (Maybe Int)
getInt = do {size <- getLine; return (readInt size)}
    
getLineLength :: IO Int
getLineLength = do 
    x <- getLine
    let nb = length x
    return nb

printAndGetLength :: String -> IO Int
printAndGetLength str = do
    putStr (str ++ "\n")
    return (length str)

printChar :: Int -> Int -> Int -> Int -> IO ()
printChar length width maxL maxW
    | length == 0 && width == 0 = putStr "+"
    | length == 0 && width == maxW = putStr "+"
    | length == maxL && width == 0 = putStr "+"
    | length == maxL && width == maxW = putStr "+"
    | (length == 0 || length == maxL ) && width > 0 && width < maxW = putStr "-"
    | (width == 0 || width == maxW) && length > 0 && length < maxL = putStr "|"
    | otherwise = putStr " "

printLine :: Int -> Int -> Int -> Int -> IO ()
printLine length width maxL maxW
    | width > maxW = putStr "\n"
printLine length width maxL maxW = do
    printChar length width maxL maxW
    printLine length (width + 1) maxL maxW

printLine' :: Int -> Int -> Int -> Int -> Int -> IO ()
printLine' length width maxL maxW size
    | length < 0 = putStr ""
printLine' length width maxL maxW size = do
    printLine length width maxL maxW
    printLine' (length - 1) width maxL maxW size

printBox :: Int -> IO ()
printBox size
    | size > 0 = printLine' size 0 size (size * 2) size
