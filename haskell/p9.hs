import Control.Monad (guard)
import Data.List (find)
import Data.Maybe (fromJust)

-- Even for brute force, this solution is pretty fugly

main = print $ (\(a, b, c) -> a*b*c) . fromJust $ pythags1000
  where 
    pythags1000 = find (\(a, b, c) -> a + b + c == 1000) . pythagTriplets $ 500 


pythagTriplets :: Int -> [(Int, Int, Int)]
pythagTriplets n = do 
    a <- [1..n]
    b <- [a..n]
    let c2 = a^2 + b^2
    guard $ isPerfectSquare c2 
    return (a, b,  floor . sqrt . fromIntegral $ c2)


isPerfectSquare :: Int -> Bool
isPerfectSquare n = sqrtCand * sqrtCand == n
  where sqrtCand = floor . sqrt . fromIntegral $ n
