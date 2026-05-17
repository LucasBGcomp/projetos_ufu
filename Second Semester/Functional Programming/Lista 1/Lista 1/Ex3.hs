import Data.Char(digitToInt)

char2num :: Char -> Int
char2num c = if c >= '0' && c <= '9' then digitToInt c else 0