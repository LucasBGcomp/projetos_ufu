acimaMedia :: (Num a, Ord a, Fractional a) => [a] -> [a]
acimaMedia [] = []
acimaMedia xs = acimaMedia' xs (media xs)
    where
        media :: Fractional a => [a] -> a
        media ys = sum ys / fromIntegral (length ys)

        acimaMedia' :: Ord a => [a] -> a -> [a]
        acimaMedia' [] _ = []
        acimaMedia' (z:zs) m = if z > m then z : acimaMedia' zs m else acimaMedia' zs m
