mySucc :: Int -> Int
mySucc x = x + 1

myIsNeg :: Int -> Bool
myIsNeg x
    | x < 0 = True
    | x >= 0 = False

myAbs :: Int -> Int
myAbs x
    | x < 0 = x * (-1)
    | x >= 0 = x

myMin :: Int -> Int -> Int
myMin a b
    | a < b = a
    | a > b = b

myMax :: Int -> Int -> Int
myMax a b
    | a < b = b
    | a > b = a

myTuple :: a -> b -> (a, b)
myTuple a b = (a, b)

myTruple :: a -> b -> c -> (a, b, c)
myTruple a b c = (a, b, c)

myFst :: (a, b) -> a
myFst (a,b) = a

mySnd :: (a, b) -> b
mySnd (a, b) = b

mySwap :: (a, b) -> (b, a)
mySwap (a, b) = (b, a)

myHead :: [a] -> a
myHead [] = error "Error: myHead: Empty list"
myHead (a:z) = a

myTail :: [a] -> [a]
myTail [] = error "Error: myTail: Empty list"
myTail (a:z) = z

myLength :: [a] -> Int
myLength [] = 0
myLength (a:z) = 1 + myLength z

myNth :: [a] -> Int -> a
myNth [] n = error "Error: myNth: Empty list"
myNth (a:z) n
    | n < 0 = error "Error: myNth: n must be postive than 0"
    | n > myLength (a:z) = error "Error: myNth: n it's too large compare to list"
myNth (a:z) n
    | n == 0 = a
    | n /= 0 = myNth z (n - 1)

myTake :: Int -> [a] -> [a]
myTake n [] = error "Error: myTake: Empty list"
myTake n (a:z)
    | n > myLength (a:z) = (a:z)
myTake n (a:z) = a : take (n - 1) z

myDrop :: Int -> [a] -> [a]
myDrop n [] = error "Error: myDrop: Empty list"
myDrop n (a:z)
    | n > myLength (a:z) = []
myDrop n (a:z) = drop (n - 1) z

myAppend :: [a] -> [a] -> [a]
myAppend a [] = a
myAppend [] b = b
myAppend (a:b) (c:d) = a : myAppend (b) (c:d)

myReverse :: [a] -> [a]
myReverse [] = []
myReverse (a:b) = myAppend (myReverse b) [a]

myInit :: [a] -> [a]
myInit [] = error "Error: myInit: Empty list"
myInit (a) = myTake (myLength a - 1) a

myLast :: [a] -> a
myLast [] = error "Error: myLast: Empty list"
myLast (x:xs)
    | (myLength (x:xs) - 1) == 0 = x
    | (myLength (x:xs) - 1) /= 0 = myLast xs

myZip :: [a] -> [b] -> [(a, b)]
myZip x [] = []
myZip [] y = []
myZip (x:xs) (y:ys) = (x, y) : myZip xs ys

myUnzip :: [(a, b)] -> ([a], [b])
myUnzip [] = ([], [])
myUnzip (x) = ( myMap myFst x, myMap mySnd x)

myMap :: (a -> b) -> [a] -> [b]
myMap func [] = []
myMap func (x:xs) = func x : myMap func xs

myFilter :: (a -> Bool) -> [a] -> [a]
myFilter _ [] = []
myFilter func (x:xs)
    | func x = x : myFilter func xs
    | otherwise = myFilter func xs

myFoldl :: (b -> a -> b) -> b -> [a] -> b
myFoldl _ var [] = var
myFoldl func var (x:xs) = myFoldl func (func var x) xs

myFirst :: [a] -> a
myFirst [] = error "Error: myFirst: Empty list"
myFirst (x:xs) = x

myFoldr :: (a -> b -> b) -> b -> [a] -> b
myFoldr _ var [] = var
myFoldr func var (x:xs) = myFoldr func (func var x) xs