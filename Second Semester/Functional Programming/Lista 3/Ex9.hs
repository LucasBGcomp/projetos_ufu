diferentes :: Eq a => [a] -> Bool
diferentes [] = True
diferentes [_] = True
diferentes (x:y:xs) = x /= y && diferentes (y:xs)