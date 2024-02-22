-- a)  pattern
-- aceptados :: (a -> Bool) -> [a] -> [a] 
-- no funciona comentar
-- aceptados _ [] = []
-- aceptados p (x:xs) = p x = x : aceptados2 p xs
-- aceptados p (x:xs) = aceptados2 p xs

aceptados2 _ [] = []
aceptados2 p (x:xs)
    | p x = x : aceptados2 p xs
    | otherwise = aceptados2 p xs

-- esPar :: Int -> Bool
esPar x = x `mod` 2 == 0

-- ej  aceptados esPar [2,2,3,3]

--b) list
comunes (x:xs) ys = [x | x <- xs, x `elem` ys]

-- comunes :: Eq a => [a] -> [a] -> [a]
comunes2 [] _ = []
comunes2 (x:xs) ys
    | x `elem` ys = x : comunes2 xs ys
    | otherwise = comunes2 xs ys

-- ej comunes ["a","b","c","d"] ["a","b"]
-- ej comunes [1,2,3,4] [1,2]

-- c) guard

-- no funciona comentar
-- subLista :: [a] -> Int -> Int -> [a]
-- subListaX [] n c = []
-- subLista (x:xs) n c 
--     | n == 0 = []
--     | c == 0 = []
--     | otherwise = subLista xs n-1 

-- subLista :: int -> [a] -> [a]
subListaX 0 lista = lista
subListaX n (_:xs)
    | n > 0 = subListaX (n - 1) xs