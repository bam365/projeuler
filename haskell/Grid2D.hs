module Grid2D 
    ( Grid2D
    , fromList
    , gridWidth
    , gridHeight
    , gridAt
    ) where

import           Data.Vector ((!))
import qualified Data.Vector as V

data Grid2D a = Grid2DP 
                { gridVector :: V.Vector (V.Vector a)
                , gridWidth  :: Int
                , gridHeight :: Int
                } 

fromList :: [[a]] -> Grid2D a
fromList l = Grid2DP gVec gWidth gHeight
  where
    gHeight = length l
    gWidth = minimum . map length $ l
    gVec = V.fromList . map (V.fromList . take gWidth) $ l


gridAt :: Int -> Int -> Grid2D a -> Maybe a
gridAt x y g 
    | x < 0 || x >= gridWidth g || y < 0 || y >= gridHeight g  = Nothing
    | otherwise = Just $ (gridVector g ! y) ! x

