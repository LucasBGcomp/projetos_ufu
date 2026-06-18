distancias :: [(Float, Float)] -> [Float]
distancias [] = []
distancias xs = [sqrt (x*x + y*y) | (x,y) <- xs]