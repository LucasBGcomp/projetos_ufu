replique :: [a] -> Int -> [a]
replique [] _ = []
replique (x:xs) n = replique' x n ++ replique xs n
    where
        replique' :: a -> Int -> [a]
        replique' _ 0 = []
        replique' y k = y : replique' y (k-1)
