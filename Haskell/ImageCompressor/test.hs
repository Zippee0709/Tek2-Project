import System.IO

f :: [String] -> [Int]
f = map read

readColorInFile :: String -> IO()
readColorInFile [] = print "error"
readColorInFile file = do
    print file
    let list = []
    -- handle <- openFile file ReadMode
    handle <- openFile "test_num.txt" ReadMode
    contents <- hGetContents handle
    let singlewords = words contents
        list = f singlewords
    print list
    hClose handle

