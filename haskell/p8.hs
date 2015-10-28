import Data.Char (isDigit)
import Eutil

main = do 
    nums <- map toDigit . filter isDigit <$> readFile "../p8.dat"
    print $ maximum . map product . groupsOf 13 $ nums


groupsOf :: Int -> [a] -> [[a]]
groupsOf _ [] = []
groupsOf n xl@(_:xs) 
    | length xl < n = []
    | otherwise = take n xl : groupsOf n xs
