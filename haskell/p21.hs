import Eutil

main = print $ sum . filter isAmicable $ [2 .. 10000 - 1]

isAmicable :: Int -> Bool
isAmicable n = pfs /= n &&  n == propFactorSum pfs
  where pfs = propFactorSum n


