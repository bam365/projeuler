-- By "first ten digits" they apparently mean 10 most-significant digits
main = do
    nums <- readFileBigInts "../p13.dat"
    putStrLn $ take 10 . show . sum $ nums

readFileBigInts :: String -> IO [Integer]
readFileBigInts f = map read . lines <$> readFile f
