{-
-- EPITECH PROJECT, 2023
-- day01
-- File description:
-- Haskell discovery
-}
mySucc :: Int -> Int
mySucc x = x + 1

myIsNeg :: Int -> Bool
myIsNeg x = if x < 0
            then True
            else False

myAbs :: Int -> Int
myAbs x = if x < 0
          then x * (-1)
          else x

myMin :: Int -> Int -> Int
myMin x y = if x < y
            then x
            else y

myMax :: Int -> Int -> Int
myMax x y = if x < y
            then y
            else x

myTuple :: a -> b -> (a, b)
myTuple x y = (x, y)

myTruple :: a -> b -> c -> (a, b, c)
myTruple x y z = (x, y, z)

myFst :: (a, b) -> a
myFst (a, b) = a

mySnd :: (a, b) -> b
mySnd (a, b) = b

mySwap :: (a, b) -> (b, a)
mySwap (a, b) = (b, a)

myHead :: [a] -> a
myHead [] = error "Empty list"
myHead (a:n) = a

myTail :: [a] -> [a]
myTail [] = error "Empty list"
myTail (a:n) = n

myLength :: [a] -> Int
myLength [] = 0
myLength (a:n) = myLength n + 1

myNth :: [a] -> Int -> a
myNth [] i = error "List empty"
myNth (a:b) i
  | myIsNeg i = error "Negative index"
myNth (a:b) i = if i == 0
                then a
                else myNth b (i - 1)

myTake :: Int -> [a] -> [a]
myTake _ [] = []
myTake 0 a = []
myTake i _
  | myIsNeg i = error "Negative index"
myTake i (a:b) = a:myTake (i - 1) b

myDrop :: Int -> [a] -> [a]
myDrop _ [] = []
myDrop 0 a = a
myDrop i (_:b) = myDrop (i - 1) b

myAppend :: [a] -> [a] -> [a]
myAppend a [] = a
myAppend [] b = b
myAppend (a:b) c = a:myAppend b c

myReverse :: [a] -> [a]
myReverse [] = []
myReverse (a:b) = myAppend (myReverse b) [a]

myInit :: [a] -> [a]
myInit [] = error "Empty list"
myInit a = myTake (myLength a - 1) a

myLast :: [a] -> a
myLast [] = error "Empty list"
myLast a = myHead (myReverse a)

myZip :: [a] -> [b] -> [(a, b)]
myZip a [] = []
myZip [] b = []
myZip (a:b) (c:d) = (a, c):myZip b d

myUnzip :: [(a, b)] -> ([a], [b])
myUnzip [] = ([], [])
myUnzip ((one, second):b) = (one:or, second:sr)
  where
    (or, sr) = myUnzip b

myMap :: (a -> b) -> [a] -> [b]
myMap _ [] = []
myMap func (a:b) = func a:myMap func b

myFilter :: (a -> Bool) -> [a] -> [a]
myFilter _ [] = []
myFilter func (a:b) = if func a
                      then a:myFilter func b
                      else myFilter func b

myUnFilter :: (a -> Bool) -> [a] -> [a]
myUnFilter _ [] = []
myUnFilter f (a:b) = if f a
                     then myUnFilter f b
                     else a:myUnFilter f b

myFoldl :: (b -> a -> b) -> b -> [a] -> b
myFoldl func start [] = start
myFoldl func start (a:b) = myFoldl func (func start a) b

myFoldr :: (a -> b -> b) -> b -> [a] -> b
myFoldr func start [] = start
myFoldr func start list = myFoldr func (func (myLast list) start) (myInit list)

myPartition :: (a -> Bool) -> [a] -> ([a], [a])
myPartition _ [] = ([], [])
myPartition func list = (myFilter func list, myUnFilter func list)

myQuickSort :: (a -> a -> Bool) -> [a] -> [a]
myQuickSort _ [] = []
myQuickSort f list = list
