intToBinario :: Int -> [Int]
intToBinario x
    |x < 0 = error "O numero deve ser positivo!"
    |otherwise = intToBinario' x
        where
            intToBinario' :: Int -> [Int]
            intToBinario' y
                | div y 2 == 0 = [mod y 2]
                | otherwise = intToBinario' (div y 2) ++ [mod y 2]