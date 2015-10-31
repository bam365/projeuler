import Data.List (find)
import Data.Maybe (fromJust)
import Eutil

main =  print $ fst .  fromJust . first1000DigNum $ zip [0..] fibonacci
  where first1000DigNum = find ((>= 1000) . length . show . snd) 

