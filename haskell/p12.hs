import Eutil
import qualified Data.Map as M

main = print $ head . dropWhile (\n -> countFactors n <= 500) $ triangleNums

