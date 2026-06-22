transposta :: Num a => [[a]] -> [[a]]
transposta [] = []
transposta ([]:_) = []
transposta xs = map head xs : transposta (map tail xs)