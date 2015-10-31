import CalendarStuff

main = 
    print $ length . filter firstSunday $ yearDataBetween 1901 2000
  where
    firstSunday (YearData _ _ d dow) = dow == Sunday && d == 1 
    


