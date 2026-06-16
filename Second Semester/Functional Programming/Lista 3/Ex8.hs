multListas :: [Int] -> [Int] -> [[Int]]
multListas [] _ = []
multListas _ [] = []
multListas (x:xs) ys = aux x ys : multListas xs ys
    where
        aux c (k:ks) = (c * k) : aux c ks
        aux _ _ = []