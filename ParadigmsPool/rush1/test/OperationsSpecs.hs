{-
-- EPITECH PROJECT, 2023
-- rush1
-- File description:
-- Haskell
-}
module OperationsSpecs
    ( testSwapA
    , testSwapB
    , testPushA
    , testPushB
    , testRotateRevA
    , testRotateRevB
    , testDoOperations
    , testCheckPushswap) where

import           Test.HUnit (assertEqual, Test(TestList, TestCase))
import           PushSwapChecker (checkPushswap, doOperations, pushA, pushB
                                , rotateRevA, rotateRevB, swapA, swapB)

testSwapA00 :: Test
testSwapA00 = TestCase (assertEqual "swapA: 0 0" ([], []) (swapA ([], [])))

testSwapA01 :: Test
testSwapA01 = TestCase (assertEqual "swapA: 0 1" ([], [1]) (swapA ([], [1])))

testSwapA10 :: Test
testSwapA10 = TestCase (assertEqual "swapA: 1 0" ([1], []) (swapA ([1], [])))

testSwapA11 :: Test
testSwapA11 = TestCase (assertEqual "swapA: 1 1" ([1], [1]) (swapA ([1], [1])))

testSwapA12 :: Test
testSwapA12 = TestCase
  (assertEqual "swapA: 1 2" ([1], [2, 3]) (swapA ([1], [2, 3])))

testSwapA21 :: Test
testSwapA21 = TestCase
  (assertEqual "swapA: 2 1" ([2, 1], [3]) (swapA ([1, 2], [3])))

testSwapA22 :: Test
testSwapA22 = TestCase
  (assertEqual "swapA: 2 2" ([2, 1], [3, 4]) (swapA ([1, 2], [3, 4])))

testSwapA23 :: Test
testSwapA23 = TestCase
  (assertEqual "swapA: 2 3" ([2, 1], [3, 4, 5]) (swapA ([1, 2], [3, 4, 5])))

testSwapA32 :: Test
testSwapA32 = TestCase
  (assertEqual "swapA: 3 2" ([2, 1, 3], [4, 5]) (swapA ([1, 2, 3], [4, 5])))

testSwapA33 :: Test
testSwapA33 = TestCase
  (assertEqual
     "swapA: 3 3"
     (swapA ([1, 2, 3], [4, 5, 6]))
     ([2, 1, 3], [4, 5, 6]))

testSwapA :: Test
testSwapA = TestList
  [ testSwapA00
  , testSwapA01
  , testSwapA10
  , testSwapA11
  , testSwapA12
  , testSwapA21
  , testSwapA22
  , testSwapA23
  , testSwapA32
  , testSwapA33]

testSwapB00 :: Test
testSwapB00 = TestCase (assertEqual "swapB: 0 0" ([], []) (swapB ([], [])))

testSwapB01 :: Test
testSwapB01 = TestCase (assertEqual "swapB: 0 1" ([], [1]) (swapB ([], [1])))

testSwapB10 :: Test
testSwapB10 = TestCase (assertEqual "swapB: 1 0" ([1], []) (swapB ([1], [])))

testSwapB11 :: Test
testSwapB11 = TestCase (assertEqual "swapB: 1 1" ([1], [1]) (swapB ([1], [1])))

testSwapB12 :: Test
testSwapB12 = TestCase
  (assertEqual "swapB: 1 2" ([1], [3, 2]) (swapB ([1], [2, 3])))

testSwapB21 :: Test
testSwapB21 = TestCase
  (assertEqual "swapB: 2 1" ([1, 2], [3]) (swapB ([1, 2], [3])))

testSwapB22 :: Test
testSwapB22 = TestCase
  (assertEqual "swapB: 2 2" ([1, 2], [4, 3]) (swapB ([1, 2], [3, 4])))

testSwapB23 :: Test
testSwapB23 = TestCase
  (assertEqual "swapB: 2 3" ([1, 2], [4, 3, 5]) (swapB ([1, 2], [3, 4, 5])))

testSwapB32 :: Test
testSwapB32 = TestCase
  (assertEqual "swapB: 3 2" ([1, 2, 3], [5, 4]) (swapB ([1, 2, 3], [4, 5])))

testSwapB33 :: Test
testSwapB33 = TestCase
  (assertEqual
     "swapB: 3 3"
     (swapB ([1, 2, 3], [4, 5, 6]))
     ([1, 2, 3], [5, 4, 6]))

testSwapB :: Test
testSwapB = TestList
  [ testSwapB00
  , testSwapB01
  , testSwapB10
  , testSwapB11
  , testSwapB12
  , testSwapB21
  , testSwapB22
  , testSwapB23
  , testSwapB32
  , testSwapB33]

testPushA00 :: Test
testPushA00 = TestCase (assertEqual "pushA: 0 0" ([], []) (pushA ([], [])))

testPushA01 :: Test
testPushA01 = TestCase (assertEqual "pushA: 0 1" ([1], []) (pushA ([], [1])))

testPushA10 :: Test
testPushA10 = TestCase (assertEqual "pushA: 1 0" ([1], []) (pushA ([1], [])))

testPushA11 :: Test
testPushA11 = TestCase
  (assertEqual "pushA: 1 1" ([2, 1], []) (pushA ([1], [2])))

testPushA12 :: Test
testPushA12 = TestCase
  (assertEqual "pushA: 1 2" ([2, 1], [3]) (pushA ([1], [2, 3])))

testPushA21 :: Test
testPushA21 = TestCase
  (assertEqual "pushA: 2 1" ([3, 1, 2], []) (pushA ([1, 2], [3])))

testPushA22 :: Test
testPushA22 = TestCase
  (assertEqual "pushA: 2 2" ([3, 1, 2], [4]) (pushA ([1, 2], [3, 4])))

testPushA23 :: Test
testPushA23 = TestCase
  (assertEqual "pushA: 2 3" ([3, 1, 2], [4, 5]) (pushA ([1, 2], [3, 4, 5])))

testPushA32 :: Test
testPushA32 = TestCase
  (assertEqual "pushA: 3 2" ([4, 1, 2, 3], [5]) (pushA ([1, 2, 3], [4, 5])))

testPushA33 :: Test
testPushA33 = TestCase
  (assertEqual
     "pushA: 3 3"
     (pushA ([1, 2, 3], [4 .. 6]))
     ([4, 1, 2, 3], [5, 6]))

testPushA :: Test
testPushA = TestList
  [ testPushA00
  , testPushA01
  , testPushA10
  , testPushA11
  , testPushA12
  , testPushA21
  , testPushA22
  , testPushA23
  , testPushA32
  , testPushA33]

testPushB00 :: Test
testPushB00 = TestCase (assertEqual "pushB: 0 0" ([], []) (pushB ([], [])))

testPushB01 :: Test
testPushB01 = TestCase (assertEqual "pushB: 0 1" ([], [1]) (pushB ([], [1])))

testPushB10 :: Test
testPushB10 = TestCase (assertEqual "pushB: 1 0" ([], [1]) (pushB ([1], [])))

testPushB11 :: Test
testPushB11 = TestCase
  (assertEqual "pushB: 1 1" ([], [1, 2]) (pushB ([1], [2])))

testPushB12 :: Test
testPushB12 = TestCase
  (assertEqual "pushB: 1 2" ([], [1, 2, 3]) (pushB ([1], [2, 3])))

testPushB21 :: Test
testPushB21 = TestCase
  (assertEqual "pushB: 2 1" ([2], [1, 3]) (pushB ([1, 2], [3])))

testPushB22 :: Test
testPushB22 = TestCase
  (assertEqual "pushB: 2 2" ([2], [1, 3, 4]) (pushB ([1, 2], [3, 4])))

testPushB23 :: Test
testPushB23 = TestCase
  (assertEqual "pushB: 2 3" ([2], [1, 3, 4, 5]) (pushB ([1, 2], [3, 4, 5])))

testPushB32 :: Test
testPushB32 = TestCase
  (assertEqual "pushB: 3 2" ([2, 3], [1, 4, 5]) (pushB ([1, 2, 3], [4, 5])))

testPushB33 :: Test
testPushB33 = TestCase
  (assertEqual
     "pushB: 3 3"
     (pushB ([1, 2, 3], [4, 5, 6]))
     ([2, 3], [1, 4, 5, 6]))

testPushB :: Test
testPushB = TestList
  [ testPushB00
  , testPushB01
  , testPushB10
  , testPushB11
  , testPushB12
  , testPushB21
  , testPushB22
  , testPushB23
  , testPushB32
  , testPushB33]

testRotateRevA00 :: Test
testRotateRevA00 = TestCase
  (assertEqual "rotateRevA: 0 0" ([], []) (rotateRevA ([], [])))

testRotateRevA01 :: Test
testRotateRevA01 = TestCase
  (assertEqual "rotateRevA: 0 1" ([1], []) (rotateRevA ([1], [])))

testRotateRevA10 :: Test
testRotateRevA10 = TestCase
  (assertEqual "rotateRevA: 1 0" ([], [1]) (rotateRevA ([], [1])))

testRotateRevA11 :: Test
testRotateRevA11 = TestCase
  (assertEqual "rotateRevA: 1 1" ([1], [2]) (rotateRevA ([1], [2])))

testRotateRevA12 :: Test
testRotateRevA12 = TestCase
  (assertEqual "rotateRevA: 1 2" ([1], [2, 3]) (rotateRevA ([1], [2, 3])))

testRotateRevA21 :: Test
testRotateRevA21 = TestCase
  (assertEqual "rotateRevA: 2 1" ([2, 1], [3]) (rotateRevA ([1, 2], [3])))

testRotateRevA22 :: Test
testRotateRevA22 = TestCase
  (assertEqual "rotateRevA: 2 2" ([2, 1], [3, 4]) (rotateRevA ([1, 2], [3, 4])))

testRotateRevA23 :: Test
testRotateRevA23 = TestCase
  (assertEqual
     "rotateRevA: 2 3"
     ([2, 1], [3, 4, 5])
     (rotateRevA ([1, 2], [3, 4, 5])))

testRotateRevA32 :: Test
testRotateRevA32 = TestCase
  (assertEqual
     "rotateRevA: 3 2"
     ([3, 1, 2], [4, 5])
     (rotateRevA ([1, 2, 3], [4, 5])))

testRotateRevA33 :: Test
testRotateRevA33 = TestCase
  (assertEqual
     "rotateRevA: 3 3"
     (rotateRevA ([1, 2, 3], [4, 5, 6]))
     ([3, 1, 2], [4, 5, 6]))

testRotateRevA :: Test
testRotateRevA = TestList
  [ testRotateRevA00
  , testRotateRevA01
  , testRotateRevA10
  , testRotateRevA11
  , testRotateRevA12
  , testRotateRevA21
  , testRotateRevA22
  , testRotateRevA23
  , testRotateRevA32
  , testRotateRevA33]

testRotateRevB00 :: Test
testRotateRevB00 = TestCase
  (assertEqual "rotateRevB: 0 0" ([], []) (rotateRevB ([], [])))

testRotateRevB01 :: Test
testRotateRevB01 = TestCase
  (assertEqual "rotateRevB: 0 1" ([], [1]) (rotateRevB ([], [1])))

testRotateRevB10 :: Test
testRotateRevB10 = TestCase
  (assertEqual "rotateRevB: 1 0" ([1], []) (rotateRevB ([1], [])))

testRotateRevB11 :: Test
testRotateRevB11 = TestCase
  (assertEqual "rotateRevB: 1 1" ([1], [2]) (rotateRevB ([1], [2])))

testRotateRevB12 :: Test
testRotateRevB12 = TestCase
  (assertEqual "rotateRevB: 1 2" ([1], [3, 2]) (rotateRevB ([1], [2, 3])))

testRotateRevB21 :: Test
testRotateRevB21 = TestCase
  (assertEqual "rotateRevB: 2 1" ([1, 2], [3]) (rotateRevB ([1, 2], [3])))

testRotateRevB22 :: Test
testRotateRevB22 = TestCase
  (assertEqual "rotateRevB: 2 2" ([1, 2], [4, 3]) (rotateRevB ([1, 2], [3, 4])))

testRotateRevB23 :: Test
testRotateRevB23 = TestCase
  (assertEqual
     "rotateRevB: 2 3"
     ([1, 2], [5, 3, 4])
     (rotateRevB ([1, 2], [3, 4, 5])))

testRotateRevB32 :: Test
testRotateRevB32 = TestCase
  (assertEqual
     "rotateRevB: 3 2"
     ([1, 2, 3], [5, 4])
     (rotateRevB ([1, 2, 3], [4, 5])))

testRotateRevB33 :: Test
testRotateRevB33 = TestCase
  (assertEqual
     "rotateRevB: 3 3"
     (rotateRevB ([1, 2, 3], [4, 5, 6]))
     ([1, 2, 3], [6, 4, 5]))

testRotateRevB :: Test
testRotateRevB = TestList
  [ testRotateRevB00
  , testRotateRevB01
  , testRotateRevB10
  , testRotateRevB11
  , testRotateRevB12
  , testRotateRevB21
  , testRotateRevB22
  , testRotateRevB23
  , testRotateRevB32
  , testRotateRevB33]

testDoOperations00 :: Test
testDoOperations00 = TestCase
  (assertEqual
     "doOperations: subject example 1"
     (Just ([1, 2, 3, 5, 6, 8], []))
     (doOperations
        ["sa", "pb", "pb", "pb", "sa", "pa", "pa", "pa"]
        ([2, 1, 3, 6, 5, 8], [])))

testDoOperations01 :: Test
testDoOperations01 = TestCase
  (assertEqual
     "doOperations: subject example 2"
     (Just ([6, 5, 8], [3, 2, 1]))
     (doOperations ["sa", "pb", "pb", "pb"] ([2, 1, 3, 6, 5, 8], [])))

testDoOperations02 :: Test
testDoOperations02 = TestCase
  (assertEqual
     "doOperations: rotations"
     (Just ([0, 1, 2, 3, 4, 5, 6, 7, 8, 9], []))
     (doOperations
        [ "rb"
        , "sc"
        , "ra"
        , "rra"
        , "pb"
        , "pb"
        , "rb"
        , "rrb"
        , "rr"
        , "rrr"
        , "pa"
        , "pa"
        , "sb"]
        ([0, 1, 2, 3, 4, 5, 6, 7, 8, 9], [])))

testDoOperations03 :: Test
testDoOperations03 = TestCase
  (assertEqual
     "doOperations: unknow operation"
     Nothing
     (doOperations
        ["rb", "sc", "ra", "pb", "rb", "test", "sb"]
        ([0, 1, 2, 3, 4, 5, 6, 7, 8, 9], [])))

testDoOperations :: Test
testDoOperations = TestList
  [ testDoOperations00
  , testDoOperations01
  , testDoOperations02
  , testDoOperations03]

testCheckPushswap00 :: Test
testCheckPushswap00 = TestCase
  (assertEqual
     "checkPushswap: simple list"
     (True, Just ([1], []))
     (checkPushswap ["pb", "pa"] [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]))

testCheckPushswap01 :: Test
testCheckPushswap01 = TestCase
  (assertEqual
     "checkPushswap: unknown operation"
     (False, Nothing)
     (checkPushswap ["test", "pa"] [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]))

testCheckPushswap :: Test
testCheckPushswap = TestList [testCheckPushswap00, testCheckPushswap01]
