cuadrados :: Int -> [Int]
cuadrados n = [x^2 | x <- [1..n]]

paresHastaN :: Int -> [Int]
paresHastaN n = [x | x <- [1..n], even x]

palabrasConA :: [String] -> [String]
palabrasConA palabras = [palabra | palabra <- palabras, 'a' `elem` palabra]

productos :: [Int] -> [Int] -> [Int]
productos lista1 lista2 = [x * y | x <- lista1, y <- lista2]

mayusculas :: String -> String
mayusculas cadena = [c | c <- cadena, c `elem` ['A'..'Z']]

divisores :: Int -> [Int]
divisores n = [x | x <- [1..n], n `mod` x == 0]

esPrimo :: Int -> Bool
esPrimo n = n > 1 && all (\x -> n `mod` x /= 0) [2..floor (sqrt (fromIntegral n))]

primosHastaN :: Int -> [Int]
primosHastaN n = [x | x <- [2..n], esPrimo x]
