lancObliquo :: Double -> Double -> Double -> Double
lancObliquo v1 a1 a2
    | a1 > 90 || a1 < 0 || a2 > 90 || a2 < 0 = error "Angulo deve ser entre 0 e 90 graus"
    | v1 <= 0 = error "Velocidade deve ser maior que 0"
    | otherwise = v2
        where v2 = v1 * sqrt (sin (2 * a1 * pi / 180) / sin (2 * a2 * pi / 180))