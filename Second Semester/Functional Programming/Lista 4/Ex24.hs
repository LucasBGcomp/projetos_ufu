inclinacao :: (Double -> Double) -> (Double -> Double)
inclinacao f = \x -> (f (x+h) - f x)/ h
    where
        h = 0.000001