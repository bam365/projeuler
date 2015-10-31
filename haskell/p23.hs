import qualified Data.Vector as V
import           Eutil

main = print $ sum . filter (not . isAbundantSum) $ [1..28123] 

isAbundant :: Int -> Bool
isAbundant n = propFactorSum n > n

abundantM :: V.Vector Bool
abundantM = V.map isAbundant $ V.enumFromTo 0 28123

isAbundantM :: Int -> Bool
isAbundantM = V.unsafeIndex abundantM

isAbundantSum :: Int -> Bool
isAbundantSum n  
    | n < 24 = False
    | otherwise = V.any isAbSum $ V.enumFromTo 12 (n `quot` 2)
  where isAbSum i = isAbundantM i && isAbundantM (n - i)
