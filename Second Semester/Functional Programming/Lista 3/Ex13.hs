tabuada :: Int -> [(Int, Int, Int)]
tabuada n = [(n, i, n * i) | i <- [1..10]]