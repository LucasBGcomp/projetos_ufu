ocorrencias :: Eq a => a -> [a] -> Int
ocorrencias _ [] = 0
ocorrencias e (x:xs)
    | e == x = 1 + ocorrencias e xs
    | otherwise = ocorrencias e xs