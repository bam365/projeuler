import Data.List (permutations)
import Eutil

-- This problem really boils down to a permutation, since every valid sequence
-- must have exactly 40 steps, with 20 of them right and 20 of then down. So
-- we're just finding ways to permute 40 moves over 2 sets of 20 identical moves
main = print $ (factorial 40) `div` ((factorial 20) * (factorial 20))

-- This was my initial try at a solution, which is intuitive but so slow that I'm not
-- even certain that it produces the correct result since I didn't have the patience
-- to let it finish
mainSlow = do 
    print $ length . permutations $ moves
  where moves = replicate 20 True ++ replicate 20 False
