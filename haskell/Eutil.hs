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
    , factorial
    , digitSum
    , intToWords
    ) where

import           Data.List (find, intersperse)
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


factorial :: Integral i => i -> i
factorial 0 = 1
factorial n = n * factorial (n - 1)


digitSum :: (Show i, Integral i) => i -> Int
digitSum = sum . map toDigit . show


intToWords :: Bool -> Int -> String
intToWords useAnd num | num >= 0 =
    concat . intersperse " " . filter (not . null) . map placesWords $ 
        [ (9, " billion", False)
        , (6, " million", False) 
        , (3, " thousand", False) 
        , (0, "", useAnd) 
        ]
  where 
    placesWords (i, word, withAnd) =
        let places3 p = num `mod` (10^(p+3)) `div` (10^p)
            n = places3 i
        in if n /= 0 then hundredsToWords withAnd n ++ word else ""

    hundredsToWords withAnd n 
        | n == 0  = ""
        | n < 100 = tensToWords tens
        | otherwise = 
            let tensPart = if tens == 0 then "" 
                           else (if withAnd then " and " else " ") ++ tensToWords tens
            in onesToWords hunds ++ " hundred" ++ tensPart
      where (hunds, tens) = n `quotRem` 100

    tensToWords n
        | n == 0 = ""
        | tens == 0 = onesToWords ones
        | n >= 10 && n < 20 = 
            [ "ten", "eleven", "twelve", "thirteen"
            , "fourteen", "fifteen", "sixteen"
            , "seventeen", "eighteen", "nineteen"
            ] !! (n - 10)
        | otherwise = 
            let tensPart = [ "", "", "twenty", "thirty", "forty"
                           , "fifty" , "sixty", "seventy"
                           , "eighty", "ninety" ] !! tens
            in tensPart ++ (if ones /= 0 then "-" ++ onesToWords ones else "")
      where (tens, ones) = n `quotRem` 10
            
    onesToWords = (["zero", "one", "two", "three", "four", 
                    "five", "six", "seven", "eight", "nine"] !!)
