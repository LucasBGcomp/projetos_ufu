positions :: (Num a, Eq a) => a -> [a] -> [Int]
positions _ [] = []
positions y xs = aux y (zip [1..] xs)
    where
        aux _ [] = []
        aux t ((z1,z2):zs)
            | t == z2  = z1 : aux t zs
            | otherwise = aux t zs