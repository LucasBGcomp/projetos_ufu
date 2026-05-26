associaIndice :: [a] -> [(Int, a)]
associaIndice x = aux 1 x
    where
        aux :: Int -> [a] -> [(Int, a)]
        aux _ [] = []
        aux i (y:ys) = (i, y) : aux (i+1) ys