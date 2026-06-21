replicador :: [Int] -> [Int]
replicador [] = []
replicador (x:xs) = replicador' x x  ++ replicador xs
    where
        replicador' :: Int -> Int -> [Int]
        replicador' 0 _ = []
        replicador' n k = k : replicador' (n-1) k