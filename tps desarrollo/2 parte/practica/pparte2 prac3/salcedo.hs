prueba = print("holaaa")

-- a)  pattern
-- resive un predicado y una lista y devuelve una lista con los elementos que cumplan el predicado

cumple p [] = []
cumple p (x:xs) = if p x then x : cumple p xs
                    else cumple p xs

esPar x = x `mod` 2 == 0

-- cumple esPar [2,2,1,1]


--b) list
-- resive dos listas y devuelve una lista con los elementos en comun de las listas

comunes xs ys = [x | x <- xs, x `elem` ys]

-- comunes [1, 2, 3] [1, 6, 3]


-- c) realizar con guards
-- resive una lista, 2 enteros n c  y devuelve una lista n elementos despues y c elementos siguienetes


borrar (x:xs) n 
    | n == 0 = (x:xs)
    | otherwise = borrar xs (n-1)  

-- borrar [1,2,3,4] 2

agregar (x:xs) n 
    | n == 0 = []
    | otherwise = x : agregar xs (n-1)  

-- agregar [1,2,3,4] 2

subLista (x:xs) b a 
    | b == 0 && a == 0 = []
    | b > 0 = subLista xs (b-1) a 
    | otherwise = x : subLista xs b (a-1)


-- subLista [1,2,3,4,5,6] 2 2