import Data.Char (toUpper)
maiusculas :: [String] -> String
maiusculas [] = []
maiusculas xs = concat (aux xs)
    where
        aux :: [String] -> [String]
        aux [] = []
        aux (y:ys) = if ys /= [] then map toUpper (y ++ " ") : aux ys else map toUpper y : aux ys