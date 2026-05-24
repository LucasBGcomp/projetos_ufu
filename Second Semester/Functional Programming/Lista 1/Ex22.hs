intersectaParabolas :: (Double, Double, Double) -> (Double, Double, Double) -> [(Double, Double)]
intersectaParabolas (a1, b1, c1) (a2, b2, c2)
    | a1 == a2 && b1 == b2 && c1 == c2 = error "As parabolas sao identicas, possuem infinitos pontos de intersecao."
    | a1 == 0 || a2 == 0 = error "As funcoes devem ser parabolas, ou seja, a1 e a2 devem ser diferentes de zero."
    | a1 == a2 && b1 == b2 = error "As parabolas sao paralelas, nao possuem pontos de intersecao."
    | a1 == a2 = let x = (c2 - c1) / (b1 - b2) in [(x, a1*x*x + b1*x + c1)]
    | otherwise = let
                   a = a1 - a2
                   b = b1 - b2
                   c = c1 - c2
                   delta = b*b - 4*a*c
                  in if delta < 0 then []
                     else if delta == 0 then [(-b/(2*a), a*(-b/(2*a))*(-b/(2*a)) + b*(-b/(2*a)) + c)]
                     else let x1 = (-b + sqrt delta) / (2*a)
                              x2 = (-b - sqrt delta) / (2*a)
                          in [(x1, a*x1*x1 + b*x1 + c), (x2, a*x2*x2 + b*x2 + c)]