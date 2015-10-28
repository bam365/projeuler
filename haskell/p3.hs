import Eutil

import Data.Map (keys)

main = print $  maximum . keys . primeFactorization  $ n
  where n = 600851475143 :: Integer
