module Triangle 
    ( Triangle
    , fromList
    , maxSum
    ) where

import qualified Data.Vector as V

data Triangle a = TriangleP (V.Vector (V.Vector a)) deriving (Show)
 

fromList :: [[a]] -> Maybe (Triangle a)
fromList [] = Nothing
fromList xs 
    | checkRows xs = Just . TriangleP . V.fromList . map V.fromList $ xs
    | otherwise    = Nothing
  where checkRows = all (== EQ) . zipWith compare [1..] . map length 


maxSum :: (Num a, Ord a) => Triangle a -> a
maxSum (TriangleP tv) = V.maximum . V.foldl fn V.empty $ tv
  where 
    fn acc v
        | V.null acc = v
        | otherwise = 
            let maxNode (a, b, c) = max (a + b) (a + c)
            in V.map maxNode $ V.zip3 v (V.snoc acc 0) (V.cons 0 acc)
