eqParabolaVD :: (Double, Double) -> Double -> (Double, Double, Double)
eqParabolaVD (x, y) yd = let 
                            p = y - yd
                            x0 = x
                            y0 = y + p
                            a = 1/(4*p)
                            b = -x0/(2*p)
                            c = (x0*x0 + y0*y0 - yd*yd)/(4*p)
                         in (a, b, c)