tamSegmento :: (Double, Double, Double) -> (Double, Double, Double) -> Double
tamSegmento (a1, b1, c1) (a2, b2, c2)
    | a1 == a2 && b1 == b2 && c1 == c2 = error "As parabolas sao identicas, possuem infinitos pontos de intersecao."
    | a1 == 0 || a2 == 0 = error "As funcoes devem ser parabolas (a1 e a2 nao podem ser zero)."
    | a1 == a2 = 0
    | otherwise = let
                    a = a1 - a2
                    b = b1 - b2
                    c = c1 - c2
                    delta = b*b - 4*a*c
                  in if delta < 0 then error "As parabolas nao se interceptam, nao ha um segmento de reta entre as intersecoes."
                     else if delta == 0 then 0
                     else let x1 = (-b + sqrt delta) / (2*a)
                              x2 = (-b - sqrt delta) / (2*a)
                              y1 = a1*x1*x1 + b1*x1 + c1
                              y2 = a1*x2*x2 + b1*x2 + c1
                          in sqrt ((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1))