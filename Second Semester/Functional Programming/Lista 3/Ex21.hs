prefixo :: Eq a => [a] -> [a] -> Bool
prefixo [] _ = True
prefixo _ [] = False
prefixo (x:xs) (y:ys) = x == y && prefixo xs ys