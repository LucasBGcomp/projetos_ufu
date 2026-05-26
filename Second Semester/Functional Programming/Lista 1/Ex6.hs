mdc :: Int -> Int -> Int -> Int
mdc a b c = mdc' (mdc' a b) c
  where
    mdc' :: Int -> Int -> Int
    mdc' 0 0 = 1
    mdc' x 0 = abs x
    mdc' 0 y = abs y
    mdc' x y = if x > y then mdc' (x - y) y else mdc' x (y - x)

mmc :: Int -> Int -> Int -> Int
mmc a b c = mmc' (mmc' a b) c
    where
        mmc' :: Int -> Int -> Int
        mmc' 0 0 = 0
        mmc' _ 0 = 0
        mmc' 0 _ = 0
        mmc' x y = abs (div (x * y) (mdc x x y))