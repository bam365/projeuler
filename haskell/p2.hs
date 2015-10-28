import Eutil

main = print $ sum . filter isEven . takeWhile (\n -> n <= 4000000) $ fibonacci
