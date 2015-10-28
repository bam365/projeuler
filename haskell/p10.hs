import Eutil

--This one isn't quiiiite sub-second, but close enough
main = print $ sum . takeWhile (< 2000000) $ primes
