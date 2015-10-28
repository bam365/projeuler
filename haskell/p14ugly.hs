import           Data.List (maximumBy)
import           Data.Ord (comparing)
import qualified Data.Map.Strict as M
import           Data.IORef
import           Eutil

main = do
    collatzLen <- memoCollatz
    cLengths <- mapM collatzLen nums
    print $ fst . maximumBy (comparing snd) $ zip nums cLengths
  where nums = [1 .. 1000000 - 1]


{- This is ugly. But fast-ish. This problem lends itself well to
 - memoization, but the problem is that:
 -
 - a) the typical lazy list-style of memoization really isn't fast enough to 
 -    yield any significant performance benefits for this problem
 - b) collatz is recursively defined, which makes it difficult to factor out
 -    the memoization from the function itself, especially since I'm using
 -    IO to do this.
 -
 - It's nice to know Haskell is capable of this kind of stuff, but it's 
 - still ugly.
 -}

memoCollatz :: IO (Int -> IO Int)
memoCollatz = do 
    mref <- newIORef $ M.empty
    return $ fnMemo mref 
  where

    fnMemo mref n = do
        m <- readIORef mref
        case M.lookup n m of
          Just v  -> return v
          Nothing -> do
              v <- collatz mref n
              modifyIORef mref $ M.insert n v
              return v

    collatz mref n  
        | n < 0 = return 0
        | n == 1 = return 1
        | otherwise = 
            let n' = if isEven n then n `quot` 2 else 3*n + 1
            in (+ 1) `fmap` fnMemo mref n'
