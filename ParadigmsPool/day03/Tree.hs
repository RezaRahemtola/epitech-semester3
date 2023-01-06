{-
-- EPITECH PROJECT, 2023
-- day03
-- File description:
-- $DESCRIPTION
-}
data Tree a = Empty
            | Node (Tree a) a (Tree a)
  deriving (Show)

-- instance (Show a) => Show (Tree a) where
--   show Empty = "Empty"
--   show (Node Empty val Empty) = "Node Empty " ++ show val ++ " Empty"
--   show (Node Empty val right) =
--     "Node Empty " ++ show val ++ " (" ++ show right ++ ")"
--   show (Node left val Empty) =
--     "Node (" ++ show left ++ ") " ++ show val ++ " Empty"
--   show (Node left val right) =
--     "Node (" ++ show left ++ ") " ++ show val ++ " (" ++ show right ++ ")"
addInTree :: Ord a => a -> Tree a -> Tree a
addInTree val Empty = Node Empty val Empty
addInTree val (Node left current right)
  | val < current = Node (addInTree val left) current right
  | otherwise = Node left current (addInTree val right)

instance Functor Tree where
  fmap _ Empty = Empty
  fmap f (Node left val right) = Node (fmap f left) (f val) (fmap f right)

listToTree :: Ord a => [a] -> Tree a
-- listToTree [] = Empty
-- listToTree (x:xs) = addInTree x (listToTree xs)
listToTree = foldr addInTree Empty

treeToList :: Tree a -> [a]
treeToList Empty = []
treeToList (Node left val right) = treeToList left ++ [val] ++ treeToList right

treeSort :: Ord a => [a] -> [a]
treeSort [] = []
treeSort list = treeToList (listToTree list)

instance Foldable Tree where
  foldMap f Empty = mempty
  foldMap f (Node left val right) =
    mappend (mappend (foldMap f left) (f val)) (foldMap f right)
