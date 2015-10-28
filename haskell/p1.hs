import Eutil

main = print $ sum . filter isMult3Or5 $ [1..999]
  where isMult3Or5 n = n `isDivisible` 3 || n `isDivisible` 5
