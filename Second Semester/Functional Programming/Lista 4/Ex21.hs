posicoes :: Eq a => a -> [a] -> [Int]
posicoes k xs = [x | (x,y) <- zip [1..] xs, k == y]