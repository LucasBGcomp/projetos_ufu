prefixo :: String -> [String] -> [String]
prefixo _ [] = []
prefixo pre (z:zs) = if concorda pre z then z : prefixo pre zs else prefixo pre zs
    where 
        concorda :: String -> String -> Bool
        concorda [] _ = True
        concorda (x:xs) (y:ys) = (x==y) && concorda xs ys
        concorda _ [] = False