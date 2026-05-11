eqRetaParabolas :: (Double, Double, Double) -> (Double, Double, Double) -> (Double, Double)
eqRetaParabolas (a1, b1, c1) (a2, b2, c2)
    | a1 == 0 || a2 == 0 = error "As funções devem ser parábolas (a1 e a2 não podem ser zero)."
    | a1 == a2 && b1 == b2 && c1 == c2 = error "As parábolas são idênticas, não há uma reta única que as intercepte."
    | a1 == a2 = error "As parábolas são paralelas, não há uma reta única que as intercepte."
    | otherwise = let
                    a = a1 - a2
                    b = b1 - b2
                    c = c1 - c2
                    delta = b*b - 4*a*c
                    x1 = (-b + sqrt delta) / (2*a)
                    x2 = (-b - sqrt delta) / (2*a)
                    y1 = a1*x1*x1 + b1*x1 + c1
                    y2 = a1*x2*x2 + b1*x2 + c1
                    m = (y2 - y1) / (x2 - x1)
                    n = y1 - m*x1
                  in if delta < 0
                     then error "As parábolas não se interceptam, não há uma reta que as intercepte."
                     else (m, n)