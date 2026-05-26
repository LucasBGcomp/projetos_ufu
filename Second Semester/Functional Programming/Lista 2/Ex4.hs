detectaAlternado :: Eq a => [a] -> Bool
detectaAlternado [] = True
detectaAlternado [_] = True
detectaAlternado (x:y:xs)
    | x == y = False
    | otherwise = detectaAlternado (y:xs)