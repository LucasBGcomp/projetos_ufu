intersectaParabolas :: (Double, Double, Double) -> (Double, Double, Double) -> [(Double, Double)]
intersectaParabolas (a1, b1, c1) (a2, b2, c2) = if a1 == a2 && b1 == b2 && c1 == c2 then error "As parábolas são idênticas, possuem infinitos pontos de interseção."
                                                else if a1 == a2 then let x = (c2 - c1) / (b1 - b2)
                                                                      in [(x + 0, a1*x*x + b1*x + c1 + 0)]
                                                else let
                                                      a = a1 - a2
                                                      b = b1 - b2
                                                      c = c1 - c2
                                                      delta = b*b - 4*a*c
                                                     in if delta < 0 then []
                                                        else if delta == 0 then [(-b/(2*a) + 0, a1*(-b/(2*a))*(-b/(2*a)) + b1*(-b/(2*a)) + c1 + 0)]
                                                        else let x1 = (-b + (sqrt delta)) / (2*a)
                                                                 x2 = (-b - (sqrt delta)) / (2*a)
                                                             in [(x1+0, a1*x1*x1 + b1*x1 + c1 + 0), (x2+0, a2*x2*x2 + b2*x2 + c2 + 0)]