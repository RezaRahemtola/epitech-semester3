{-
-- EPITECH PROJECT, 2023
-- day02
-- File description:
-- Haskell
-}
import           System.Environment
import           Data.Char (isDigit)
import           System.Exit
import           Data.Maybe

myElem :: Eq a => a -> [a] -> Bool
myElem _ [] = False
myElem e (x:xs) = e == x || myElem e xs

safeDiv :: Int -> Int -> Maybe Int
safeDiv _ 0 = Nothing
safeDiv num denum = Just (num `div` denum)

safeNth :: [a] -> Int -> Maybe a
safeNth [] _ = Nothing
safeNth list i
  | i < 0 || length list < i = Nothing
safeNth (a:b) i = if i == 0
                  then Just a
                  else safeNth b (i - 1)

safeSucc :: Maybe Int -> Maybe Int
safeSucc Nothing = Nothing
safeSucc (Just i) = Just (i + 1)

myLookup :: Eq a => a -> [(a, b)] -> Maybe b
myLookup _ [] = Nothing
myLookup eq ((xFst, xScd):xs)
  | eq == xFst = Just xScd
  | otherwise = myLookup eq xs

maybeDo :: (a -> b -> c) -> Maybe a -> Maybe b -> Maybe c
maybeDo _ _ Nothing = Nothing
maybeDo _ Nothing _ = Nothing
maybeDo f (Just a) (Just b) = Just (f a b)

readInt :: [Char] -> Maybe Int
readInt [] = Nothing
readInt "-" = Nothing
readInt input
  | head input == '-' && all isDigit (tail input) = Just (read input)
  | all isDigit input = Just (read input)
  | otherwise = Nothing

getLineLength :: IO Int
-- getLineLength = do
--   str <- getLine
--   return (length str)
getLineLength = length <$> getLine

printAndGetLength :: String -> IO Int
printAndGetLength str = putStrLn str >> return (length str)

printLineBox :: Int -> Int -> IO ()
printLineBox 0 _ = return ()
printLineBox nb n
  | nb >= 1 = putStrLn ("|" ++ replicate (n - 2) ' ' ++ "|")
    >> printLineBox (nb - 1) n

printBox :: Int -> IO ()
printBox 1 = putStrLn "++"
printBox n
  | n > 1 = putStrLn ("+" ++ replicate (n * 2 - 2) '-' ++ "+")
    >> printLineBox (n - 2) (n * 2)
    >> putStrLn ("+" ++ replicate (n * 2 - 2) '-' ++ "+")
  | otherwise = pure ()

concatLines :: Int -> IO String
concatLines nb
  | nb <= 0 = return ""
concatLines nb = do
  curr <- getLine
  next <- concatLines (nb - 1)
  return (curr ++ next)

getInt :: IO (Maybe Int)
-- getInt = do
--     str <- getLine
--     return (readInt str)
getInt = readInt <$> getLine

--- Do Op
hasError :: [String] -> Bool
hasError [a, b, c]
  | not (myElem b ["+", "-", "*", "/", "%"]) = True
  | isNothing (readInt a) || isNothing (readInt c) = True
  | otherwise = False
hasError _ = True

doop :: Int -> String -> Int -> IO ()
doop nb1 "+" nb2 = print (nb1 + nb2)
doop nb1 "-" nb2 = print (nb1 - nb2)
doop nb1 "*" nb2 = print (nb1 * nb2)
doop nb1 "%" nb2 = print (nb1 `mod` nb2)
doop nb1 "/" nb2 = if isNothing (safeDiv nb1 nb2)
                   then exitWith (ExitFailure 84)
                   else print (nb1 `div` nb2)
doop _ _ _ = pure ()

main :: IO ()
main = do
  argv <- getArgs
  if hasError argv
    then exitWith (ExitFailure 84)
    else doop (read (head argv)) (argv !! 1) (read (argv !! 2))
