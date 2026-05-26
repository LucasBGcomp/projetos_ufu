duplicaLista :: [a] -> [a]
duplicaLista [] = []
duplicaLista (x:xs) = x : x : duplicaLista xs