import Eutil

main = print $ sum . map wordLength $ [1..1000]
  where spaceOrDash = (`elem` ['-', ' '])
        wordLength = length . filter (not . spaceOrDash) . intToWords True
