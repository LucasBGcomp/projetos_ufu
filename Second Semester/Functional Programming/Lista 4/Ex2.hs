expande :: (a -> Bool) -> [a] -> [[a]]
expande _ [] = []
expande p (x:xs)
    |p x       = let (s, r) = span p (x:xs) in s : expande p r
    |otherwise = let (s, r) = break p (x:xs) in s : expande p r