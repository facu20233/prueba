-- prueba = print("holaaa")

-- a)  pattern
-- resive un predicado y una lista y devuelve una lista con los elementos que cumplan el predicado

aceptadosPattern _ [] = [] 
aceptadosPattern p (x:xs) = if p x then x : aceptadosPattern p xs
                    else aceptadosPattern p xs

aceptadosGuards p xs
    | xs == [] = []
    | p (head xs) = head xs : aceptadosGuards p (tail xs)
    | otherwise = aceptadosGuards p (tail xs)


aceptadosList p xs = [x | x <- xs, p x]

aceptadosMezclado p (x:xs)
    | (x:xs) == [] = []
    | p x = x : aceptadosGuards p xs
    | otherwise = aceptadosGuards p xs

-- esPar :: Int -> Bool
esPar x = x `mod` 2 == 0

-- ej  aceptadosMezclado esPar [2,2,3,3]

--b) list
-- resive dos listas y devuelve una lista con los elementos en comun de las listas
comunesList xs ys = [x | x <- xs, x `elem` ys]

comunesPattern [] _ = []
comunesPattern (x:xs) ys = if  x `elem` ys then x : comunesPattern xs ys
                    else comunesPattern xs ys

comunesGuards xs ys
    | xs == [] = []
    |  head xs `elem` ys = head xs : comunesGuards (tail xs) ys
    | otherwise = comunesPattern (tail xs) ys
    
comunesMezclado (x:xs) ys
    | (x:xs) == [] = []
    |  x `elem` ys = x : comunesGuards xs ys
    | otherwise = comunesPattern xs ys




-- comunesMezclado [1,2,3] [2,3]

-- c) realizar con guards
-- resive una lista, 2 enteros n c  y devuelve una lista n elementos despues y c elementos siguienetes


borrar xs n 
    | n == 0 = xs
    | otherwise = borrar (tail xs) (n-1)  

-- borrar [1,2,3,4] 2

agregar xs n 
    | n == 0 = []
    | otherwise = head xs : agregar (tail xs) (n-1)  

-- agregar [1,2,3,4] 2

subListaGuards xs b a 
    | b == 0 && a == 0 = []
    | b > 0 = subListaGuards  (tail xs) (b-1) a 
    | otherwise = head xs : subListaGuards (tail xs) b (a-1)

subListaPattern _ 0 0 = []
subListaPattern (x:xs) b a = if b > 0 then subListaMezclado  xs (b-1) a
                            else x : subListaMezclado xs b (a-1)

-- subListaList xs b a = [x | x <- xs, ]

subListaMezclado (x:xs) b a 
    | b == 0 && a == 0 = []
    | b > 0 = subListaMezclado  xs (b-1) a 
    | otherwise = x : subListaMezclado xs b (a-1)

-- subListaPattern [1,2,3,4,5,6] 2 2

