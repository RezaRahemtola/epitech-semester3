{-
-- EPITECH PROJECT, 2023
-- rush1
-- File description:
-- Checker
-}
module PushSwapChecker
    ( checkPushswap
    , doOperations
    , swap
    , swapA
    , swapB
    , pushA
    , pushB
    , rotate
    , rotateA
    , rotateB
    , rotateRev
    , rotateRevA
    , rotateRevB) where

import           Data.List (sort)

checkPushswap :: [String] -> [Int] -> (Bool, Maybe ([Int], [Int]))
checkPushswap instructions ints =
  let resultLists = doOperations instructions (ints, [])
  in (areListsOk resultLists, resultLists)

doOperations :: [String] -> ([Int], [Int]) -> Maybe ([Int], [Int])
doOperations ("sa":actionsRest) lists = doOperations actionsRest $ swapA lists
doOperations ("sb":actionsRest) lists = doOperations actionsRest $ swapB lists
doOperations ("sc":actionsRest) lists =
  doOperations actionsRest $ swapA $ swapB lists
doOperations ("pa":actionsRest) lists = doOperations actionsRest $ pushA lists
doOperations ("pb":actionsRest) lists = doOperations actionsRest $ pushB lists
doOperations ("ra":actionsRest) lists =
  doOperations actionsRest $ rotateA lists
doOperations ("rb":actionsRest) lists =
  doOperations actionsRest $ rotateB lists
doOperations ("rr":actionsRest) lists =
  doOperations actionsRest $ rotateA $ rotateB lists
doOperations ("rra":actionsRest) lists =
  doOperations actionsRest $ rotateRevA lists
doOperations ("rrb":actionsRest) lists =
  doOperations actionsRest $ rotateRevB lists
doOperations ("rrr":actionsRest) lists =
  doOperations actionsRest $ rotateRevA $ rotateRevB lists
doOperations [] lists = Just lists
doOperations _ _ = Nothing

swap :: [Int] -> [Int]
swap (first:second:rest) = second:first:rest
swap list = list

swapA :: ([Int], [Int]) -> ([Int], [Int])
swapA (listA, listB) = (swap listA, listB)

swapB :: ([Int], [Int]) -> ([Int], [Int])
swapB (listA, listB) = (listA, swap listB)

pushA :: ([Int], [Int]) -> ([Int], [Int])
pushA (listA, first:rest) = (first:listA, rest)
pushA lists = lists

pushB :: ([Int], [Int]) -> ([Int], [Int])
pushB (first:rest, listB) = (rest, first:listB)
pushB lists = lists

rotate :: [Int] -> [Int]
rotate (first:second:rest) = second:rest ++ [first]
rotate list = list

rotateA :: ([Int], [Int]) -> ([Int], [Int])
rotateA (listA, listB) = (rotate listA, listB)

rotateB :: ([Int], [Int]) -> ([Int], [Int])
rotateB (listA, listB) = (listA, rotate listB)

rotateRev :: [Int] -> [Int]
rotateRev [] = []
rotateRev list = last list:take (length list - 1) list

rotateRevA :: ([Int], [Int]) -> ([Int], [Int])
rotateRevA (listA, listB) = (rotateRev listA, listB)

rotateRevB :: ([Int], [Int]) -> ([Int], [Int])
rotateRevB (listA, listB) = (listA, rotateRev listB)

areListsOk :: Maybe ([Int], [Int]) -> Bool
areListsOk (Just (list, [])) = list == sort list
areListsOk _ = False
