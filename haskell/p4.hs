main = print . maximum $ 
    [i * j | i <- [100..999], j <- [i..999], isPalindrome (i * j)]

-- Using show to do this isn't entirely safe, so not putting it in Eutil
isPalindrome :: Int -> Bool
isPalindrome n = showN == reverse showN
  where showN = show n
    
