transf :: [a] -> [a]
transf xs
    |length xs < 4 = xs
    |otherwise = aux (take 2 xs) (drop 2 (take (length xs - 2) xs)) (drop (length xs - 2) xs)
    where
        aux :: [a] -> [a] -> [a] -> [a]
        aux (z:c:_) ys (w:k:_) = [c,z] ++ ys ++ [k,w]