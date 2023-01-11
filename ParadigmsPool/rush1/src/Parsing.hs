{-
-- EPITECH PROJECT, 2023
-- rush1
-- File description:
-- Haskell
-}
module Parsing (getArguments) where

import           Data.Maybe (isJust)
import           Data.Char (isDigit)

readInt :: [Char] -> Maybe Int
readInt [] = Nothing
readInt "-" = Nothing
readInt input
  | head input == '-' && all isDigit (tail input) = Just (read input)
  | all isDigit input = Just (read input)
  | otherwise = Nothing

areNumbersValid :: [String] -> Bool
areNumbersValid = all (isJust . readInt)

getNumbers :: [String] -> Maybe [Int]
getNumbers list
  | areNumbersValid list = Just (map read list)
  | otherwise = Nothing

getArguments :: [String] -> String -> (Maybe [Int], Maybe [String])
getArguments cliArgs stdInput = (getNumbers cliArgs, Just (words stdInput))
