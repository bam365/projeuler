{-# LANGUAGE FlexibleContexts #-}
import           Data.List (maximumBy)
import           Data.Ord (comparing)
import           Control.Monad.Memo
import           Eutil

-- Really nice memoized solution, using monad-memo package

main = do
    let cLengths = startEvalMemo $ mapM collatzM nums
    print $ fst . maximumBy (comparing snd) $ zip nums cLengths
  where 
    maxN = 1000000 - 1
    nums = [1 .. maxN ] 
 

collatzM :: (MonadMemo Int Int m) => Int -> m Int
collatzM n 
    | n < 1  = return 0
    | n == 1 = return 1
    | otherwise =
        let n' = if isEven n then n `quot` 2 else 3*n + 1
        in (+ 1) `fmap` memo collatzM n'
