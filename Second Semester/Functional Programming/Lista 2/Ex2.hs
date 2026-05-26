isPrime :: Int -> Bool
isPrime n
    | n < 2 = error "O numero deve ser maior ou igual a 2!"
    | otherwise = aux n 2
        where
            aux :: Int -> Int -> Bool
            aux p d
                | d > div p 2 = True
                | mod p d == 0 = False
                | otherwise = aux p (d + 1)