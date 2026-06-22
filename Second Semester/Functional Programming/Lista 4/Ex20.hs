distancias :: [(Double, Double)] -> [Double]
distancias [] = []
distancias xys = [sqrt (x*x + y*y) | (x,y) <- xys]