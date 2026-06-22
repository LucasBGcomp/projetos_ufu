func :: Double -> Double -> Int -> [Double]
func _ _ 0 = []
func a r n = [(a*r) ^ k | k <- [1..n]]