intersecao :: Eq a => [a] -> [a] -> [a]
intersecao [] _ = []
intersecao _ [] = []
intersecao (x:xs) ys
    | x `elem` ys = x : intersecao xs ys
    | otherwise = intersecao xs ys