module Eutil 
    ( isDivisible
    , isDivisor
    , isEven
    , isOdd
    , primes
    , primeFactorization
    , pfToNum
    , fastLCM
    , fibonacci
    , toDigit
    , triangleNums
    , countFactors
    ) where

import           Data.List (find)
import qualified Data.Map as M
import           Data.Maybe (fromJust)


isDivisible :: (Integral i, Eq i) => i -> i -> Bool
isDivisible d n = (d `mod` n) == 0

isDivisor :: (Integral i, Eq i) => i -> i -> Bool
isDivisor  = flip isDivisible

isEven :: Integral i => i -> Bool
isEven = (`isDivisible` 2) 

isOdd :: Integral i => i -> Bool
isOdd = not . isEven 

--  lmerge and ldiff are just for prime sieve

lmerge :: (Ord a) => [a] -> [a] -> [a]
lmerge xs@(x:xt) ys@(y:yt) = 
  case compare x y of
    LT -> x : (lmerge xt ys)
    EQ -> x : (lmerge xt yt)
    GT -> y : (lmerge xs yt)

ldiff :: (Ord a) => [a] -> [a] -> [a]
ldiff xs@(x:xt) ys@(y:yt) = 
  case compare x y of
    LT -> x : (ldiff xt ys)
    EQ -> ldiff xt yt
    GT -> ldiff xs yt


primes :: Integral i => [i]
primes = [2, 3, 5] ++ (ldiff [7, 9 ..] nonPrimes) 

nonPrimes :: Integral i => [i]
nonPrimes = foldr1 f $ map g $ tail primes
  where 
    f (x:xt) ys = x : (lmerge xt ys)
    g p = [ n * p | n <- [p, p + 2 ..]]  


primeFactorization :: Integral i => i -> M.Map i i
primeFactorization n 
    | n < 2 = M.empty
    | otherwise = loop M.empty n
  where
    loop acc 1 = acc
    loop acc i = 
        let divis = fromJust . find (`isDivisor` i) $ primes
        in loop (M.insertWith (+) divis 1 acc) (i `quot` divis)


pfToNum :: Integral i => M.Map i i -> i
pfToNum = M.foldlWithKey (\a k v -> a * (k ^ v)) 1


fastLCM :: [Int] -> Int
fastLCM  = pfToNum . M.unionsWith max . map primeFactorization


fibonacci :: [Int]
fibonacci = 0 : 1 : zipWith (+) fibonacci (tail fibonacci)


toDigit :: Char -> Int
toDigit c = fromEnum c - fromEnum '0'


triangleNums :: Integral i => [i]
triangleNums = 1 : zipWith (+) [2..] triangleNums


countFactors :: Integral i => i -> i
countFactors = product . map (+ 1) . M.elems . primeFactorization 
