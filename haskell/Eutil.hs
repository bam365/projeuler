module Eutil 
( isDivisible
, isDivisor
, primeSieve
) where


isDivisible :: Int -> Int -> Bool
isDivisible d n = (n `mod` d) == 0

isDivisor  = flip isDivisible


primeSieve :: Int -> [Int]
primeSieve n = sieve [2..n]
        where sieve [] = []
              sieve (x:xs) = x : (sieve . filter (not . isDivisible x) $ xs)
