crivo :: [Int] -> [Int]
crivo [] = []
crivo [x] = [x]
crivo (x:xs) = if crivo' x xs then x : crivo xs else crivo xs
    where
        crivo' :: Int -> [Int] -> Bool
        crivo' _ [] = True
        crivo' y (z:zs) = mod z y /= 0 && crivo' y zs

primos :: Int -> [Int]
primos 0 = []
primos n = peneira [2..n]
    where
        peneira (p:xs) = p : peneira [x | x <- xs, mod x p > 0]
        peneira _ = []