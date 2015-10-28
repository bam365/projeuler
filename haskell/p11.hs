import           Data.Maybe (catMaybes)
import qualified Grid2D as G

main = do
    grid <- (integerGrid . lines) `fmap` readFile "../p11.dat"
    print $ maximum . allAdjacentProducts 4 $ grid
  where 
    integerGrid  :: [String] -> G.Grid2D Integer
    integerGrid = G.fromList . map (map read . words)

    allAdjacentProducts n g = do
        x <- [0 .. G.gridWidth g - 1]
        y <- [0 .. G.gridHeight g - 1]
        map (coordsProduct g) . allAdjacentLines n $ (x, y) 

    coordsProduct g = product . catMaybes . map (\(x, y) -> G.gridAt x y g) 


coordLine :: Int -> (Int -> Int) -> (Int -> Int) -> (Int, Int) -> [(Int, Int)]
coordLine n xFn yFn (xInit, yInit) = zip (cSeq xFn xInit) (cSeq yFn yInit)
  where cSeq f = take n . iterate f

allAdjacentLines :: Int -> (Int, Int) -> [[(Int, Int)]]
allAdjacentLines n cInit = tail $ -- removes the result of (id, id)
    coordLine <$> pure n <*> ops <*> ops <*> pure cInit  
  where ops = [id, (+ 1), \v -> v - 1] 
