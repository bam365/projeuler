main = putStrLn $ (lexPermute "0123456789") !! (1000000 - 1)
     
lexPermute :: [a] -> [[a]]
lexPermute [] = []
lexPermute [x] = [[x]]
lexPermute xs = 
    concatMap (\(x:xs') -> map (x :) $ lexPermute xs') . lexHeads $ xs


lexHeads :: [a] -> [[a]]
lexHeads = loop [] []
  where 
    loop acc _ [] = acc
    loop acc lacc (x:xs) = loop (acc ++ [x:(lacc++xs)]) (lacc ++ [x]) xs
