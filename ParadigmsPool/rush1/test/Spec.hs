{-
-- EPITECH PROJECT, 2023
-- rush1
-- File description:
-- Haskell
-}
import           Test.HUnit (runTestTT)
import           OperationsSpecs

main :: IO ()
main = runTestTT testSwapA
  >> runTestTT testSwapB
  >> runTestTT testPushA
  >> runTestTT testPushB
  >> runTestTT testRotateRevA
  >> runTestTT testRotateRevB
  >> runTestTT testDoOperations
  >> runTestTT testCheckPushswap
  >> return ()
