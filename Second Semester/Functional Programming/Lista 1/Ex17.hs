tempodecaimento :: Double -> Int -> (Double, Int)
tempodecaimento m t
    | m < 0.5 = (m, t)
    | otherwise = tempodecaimento (m/2) (t+50)


decaimento :: Double -> (Double, Double, (Int, Int, Int))
decaimento mi =
    let (mf, tf) = tempodecaimento mi 0
        h = tf `div` 3600
        m = (tf `mod` 3600) `div` 60
        s = (tf `mod` 3600) `mod` 60
    in (mi, mf, (h, m, s))