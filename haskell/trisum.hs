import           Data.Maybe
import qualified Triangle as T

main = do
    triangle <- readTriangle <$> getContents
    print $ T.maxSum triangle
  where
    readTriangle :: String -> T.Triangle Integer
    readTriangle = fromJust . T.fromList . linesToIntList
    linesToIntList = map (map read . words) . lines

