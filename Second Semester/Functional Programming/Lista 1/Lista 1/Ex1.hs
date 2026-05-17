minimo :: Int -> Int -> Int
minimo x y = if x < y then x else y

min3 :: Int -> Int -> Int -> Int
min3 x y z = if x < y
             then if x < z then x else z
             else if y < z then y else z

maximo :: Int -> Int -> Int
maximo x y = if x > y then x else y

max3 :: Int -> Int -> Int -> Int
max3 x y z = if x > y
             then if x > z then x else z
             else if y > z then y else z