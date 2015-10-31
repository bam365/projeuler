module CalendarStuff
    ( DayOfWeek (..)
    , Month (..)
    , monthDays
    , yearDays
    , nthYearDays
    , isLeapYear
    , YearData (..)
    , yearDataSince1900
    , yearDataBetween
    ) where

import Eutil

data DayOfWeek = Sunday | Monday | Tuesday | Wednesday 
               | Thursday | Friday | Saturday
               deriving (Show, Eq, Ord, Enum, Bounded)

data Month = January | February | March | April | May | June
            | July | August | September | October | November
            | December
            deriving (Show, Eq, Ord, Enum, Bounded)

monthDays :: Bool -> Month -> [Int]
monthDays isLeap m
    | m == February = [1 .. if isLeap then 29 else 28]
    | m `elem` [September, April, June, November] = [1..30]
    | otherwise = [1..31]

yearDays :: Bool -> [(Month, Int)]
yearDays isLeap = pairZip . map (\m -> (m, monthDays isLeap m)) $ [January .. December]

nthYearDays :: Int -> [(Month, Int)]
nthYearDays = yearDays . isLeapYear

isLeapYear :: Int -> Bool
isLeapYear y
    | y `isDivisible` 1000 = y `isDivisible` 400 
    | otherwise = y `isDivisible` 4

data YearData = YearData
                 { ydYear :: Int
                 , ydMonth :: Month
                 , ydDay :: Int
                 , ydDayOfWeek :: DayOfWeek
                 } deriving (Eq, Show)


yearDataSince1900 :: [YearData]
yearDataSince1900 = map toYearData . addWeekdays . pairZip . map expandYear $ years
  where
    toYearData (dow, (y, (m, d))) = YearData y m d dow
    addWeekdays = zip (cycle [Sunday .. Saturday])
    expandYear y = (y, nthYearDays y)
    years = [1900 .. ]


yearDataBetween :: Int -> Int -> [YearData]
yearDataBetween i j
    | i < 1900 = []
    | otherwise = cullYears yearDataSince1900
  where 
    cullYears = takeWhile ((<= j) . ydYear) . dropWhile ((< i) . ydYear)


pairZip :: [(a, [b])] -> [(a, b)]
pairZip = concatMap (\(a, b) -> zip (repeat a) b)
