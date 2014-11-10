import qualified Data.Map.Strict as M
import Data.Maybe (fromJust, maybe)
import Data.List (find)
import Eutil

main = print $ myLCM [2 .. 20]

myLCM :: [Int] -> Int
myLCM  = pfToNum . M.unionsWith max . map primeFactorization
  where primes = primeSieve 20
        primeFactorization =
            let addPF = M.alter $ Just . maybe 1 (1+)
                loop acc n
                       | n `elem` primes = addPF n acc
                       | otherwise = loop (addPF pf acc) (n `quot` pf)
                           where pf = fromJust . find (isDivisor n) $ primes
            in loop M.empty           
        pfToNum = M.foldlWithKey (\a k v -> a * (k ^ v)) 1
