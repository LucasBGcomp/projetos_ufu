maiusculas :: String -> String
maiusculas [] = []
maiusculas (x:xs)
    | x >= 'A' && x <= 'Z' = x : maiusculas xs
    | x >= 'a' && x <= 'z' = (toEnum (fromEnum x - 32)) : maiusculas xs
    | otherwise = x : maiusculas xs