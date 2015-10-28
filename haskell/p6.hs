-- What they actually want is the difference between the square of the sums 
-- and the sum of the squares, not the other way around as the question
-- suggests
main = print $ squareSum nums - sumSquares nums
  where 
    sumSquares = sum . map (^ 2)
    squareSum = (^ 2) . sum
    nums = [1..100 :: Integer]
        
