quantosSegundos :: Int -> Int -> Int -> Int
quantosSegundos h m s = (h * 3600) + (m * 60) + s

converterSegundos :: Int -> (Int, Int, Int)
converterSegundos s = (h, m, sr)
    where
        h = div s 3600
        m = div (mod s 3600) 60
        sr = mod (mod s 3600) 60