segmentos :: (a -> Bool) -> [a] -> [[a]]
segmentos _ [] = []
segmentos p xs = let (y, ys) = span p xs in y : segmentos p (rmv p ys)
    where
        rmv :: (a -> Bool) -> [a] -> [a]
        rmv _ [] = []
        rmv pr (z:zs) = if not (pr z) then rmv pr zs else z : zs