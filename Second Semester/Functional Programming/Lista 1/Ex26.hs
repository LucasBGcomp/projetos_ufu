altura :: Double -> Double -> Double
altura v t
    | t == 0 = 0
    | t < 0 = error "O tempo não pode ser negativo."
    | v < 0 = error "A velocidade inicial não pode ser negativa."
    | otherwise = if h < 0 then 0 else h
    where h = (v * t) - (0.5 * 9.8 * t*t)