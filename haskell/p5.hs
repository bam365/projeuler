import Text.Printf
import Eutil
        

primeFactor :: Int -> [(Int, Int)]
primeFactor n =
        let incPrimeMultiple pf p = map (\t@(n, m) -> if (n == p) then (n, m+1) else t) pf
            divp 1 pf = pf
            divp n pf =  divp (quot n mindiv) (incPrimeMultiple pf mindiv)
                where mindiv = fst . head . filter (isDivisor n . fst) $ pf 
        in filter (not . (== 0) . snd) (divp n initialPF) 
                where initialPF = map (\p -> (p, 0)) (primeSieve n)


numFromPF xs = foldl (*) 1 $ map (\(p, m) -> p ^ m) xs


myLCM [] = 0
myLCM xs = 
        let greaterPF x [] = x
            greaterPF [] y = y
            greaterPF f@(x:xs) s@(y:ys) =  
                    if (fst x) < (fst y) then x : (greaterPF xs s)
                    else if (fst x) > (fst y) then y : (greaterPF f ys)
                    else (if (snd x) > (snd y) then x else y) : (greaterPF xs ys)
            lcmPF = foldl1 greaterPF
        in numFromPF . lcmPF $ [primeFactor x | x <- xs]

main = do
        let lcmrange = [2..20] 
        printf "The LCM of all numbers in range %s\n  is %d\n" (show lcmrange) (myLCM lcmrange)
