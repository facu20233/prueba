factorial :: Integer -> Integer
factorial 0 = 1
factorial n = n * factorial (n - 1)

fibonacci :: Integer -> Integer
fibonacci 0 = 0
fibonacci 1 = 1
fibonacci n = fibonacci (n - 1) + fibonacci (n - 2)

maximo :: Ord a => a -> a -> a
maximo x y
  | x >= y    = x
  | otherwise = y

longitud :: [a] -> Int
longitud [] = 0
longitud (_:xs) = 1 + longitud xs

pertenece :: Eq a => a -> [a] -> Bool 
pertenece _ [] = False
pertenece x (y:ys)
  | x == y    = True
  | otherwise = pertenece x ys

