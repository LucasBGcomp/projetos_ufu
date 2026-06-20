produtoImpares :: [Int] -> Int
produtoImpares [] = 1
produtoImpares xs = foldr (*) 1 (filter odd xs)