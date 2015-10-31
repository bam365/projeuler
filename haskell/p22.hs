import           Data.List (groupBy, sort)
import qualified Data.Vector as V

main = do
    names <- toNames <$> readFile "../p22.dat"
    print $ V.sum . V.imap (\i n -> nameScore n * (i + 1)) $ names

toNames :: String -> V.Vector String
toNames =  V.fromList . sort . removeEmpty . map removeSpecial . sepByCommas
  where
    removeEmpty = filter (not . null)
    removeSpecial = filter (not . (`elem` ",\""))
    sepByCommas = groupBy (\a b -> a /= ',' && b /= ',')


nameScore :: String -> Int
nameScore = sum . map letterScore
  where letterScore c = fromEnum c - fromEnum 'A' + 1
