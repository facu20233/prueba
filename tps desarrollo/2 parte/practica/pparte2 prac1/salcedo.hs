prueba = print("holaaa")

-- a)  pattern
-- resive un predicado y una lista y devuelve una lista con los elementos que cumplan el predicado

-- verificar :: (a -> Bool) -> [a] -> [a] 
verificar _ [] = []
verificar p (x:xs) = if p x then x : verificar p xs
                    else verificar p xs


-- verificar2 :: (a -> Bool) -> [a] -> Bool 
verificar2 _ [] = True
verificar2 p (x:xs)
    | p x = verificar2 p xs
    | otherwise = False

-- espar :: int -> Bool
esPar x = x `mod` 2 == 0

-- multiplicarx2 :: int -> int 
multiplicarx2 x = x*2 

-- ej  verificar esPar [2,2,3,3]


--b) list
-- resive dos listas y devuelve una lista con los elementos en comun de las listas

-- comun :: [a] -> [a] -> [a]
comun xs ys = [x | x <- xs, x `elem` ys]

-- diferencia :: Eq a => [a] -> [a] -> [a]
diferencia [] _ = []
diferencia (x:xs) ys
    | x `elem` ys = diferencia xs ys        -- elem compara cada elemento x con []
    | otherwise = x : diferencia xs ys 

-- ej comunes ["a","b","c","d"] ["a","b"]
-- ej comunes [1,2,3,4] [1,2]

-- c) realizar con guards
-- resive una lista, 2 enteros n c  y devuelve una lista n elementos despues y c elementos siguienetes

-- subLista :: int -> int -> [a] -> [a]
subLista 0 0 lista = []
subLista n c (x:xs) 
    | n > 0 && c > 0 = subLista (n - 1) c xs
    | c > 0 && n == 0 = x : subLista n (c - 1) xs

-- subLista :: Int -> [a] -> [a]
-- borra
subLista1 0 lista = lista
subLista1 n (_:xs)
    | n > 0 = subLista1 (n - 1) xs

-- agrega
subLista2 0 lista = []
subLista2 n (x:xs)
    | n > 0 = x : subLista2 (n - 1) xs

-- ej: subLista 2 3 [1,2,3,4,5,6,7,8]
-- ej: subLista2 2 [1,2,3,4,5,6,7,8]
-- ej: subLista3 2 [1,2,3,4,5,6,7,8]
