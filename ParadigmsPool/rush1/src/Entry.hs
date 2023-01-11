{-
-- EPITECH PROJECT, 2023
-- rush1
-- File description:
-- Haskell
-}
module Entry (entry) where

import           System.Environment (getArgs)
import           System.Exit (exitWith, ExitCode(ExitFailure))
import           PushSwapChecker (checkPushswap)
import           Parsing (getArguments)

exitError :: Maybe ([Int], [Int]) -> IO ()
exitError (Just lists) = putStrLn ("KOA: " ++ show lists)
  >> exitWith (ExitFailure 84)
exitError _ = putStrLn "KO" >> exitWith (ExitFailure 84)

exitIfInvalidArgsOrWrongPushSwap :: (Maybe [Int], Maybe [String]) -> IO ()
exitIfInvalidArgsOrWrongPushSwap (Just numbers, Just operations) =
  let (listsOK, result) = checkPushswap operations numbers
  in if listsOK
     then return ()
     else exitError result
exitIfInvalidArgsOrWrongPushSwap _ = exitError Nothing

entry :: IO ()
entry = do
  cliArgs <- getArgs
  stdInput <- getLine
  exitIfInvalidArgsOrWrongPushSwap $ getArguments cliArgs stdInput
  putStrLn "OK"
