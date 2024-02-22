prueba = print("holaaa")

-- a)  pattern 1234
-- resive un predicado y una lista y devuelve una lista con los elementos que cumplan el predicado

-- cumplePredicado :: (a -> Bool) -> [a] -> Bool 
cumplePredicado _ [] = []
cumplePredicado p (x:xs) = if p x then x : cumplePredicado p xs
                            else cumplePredicado p xs

esPar x = x `mod` 2 == 0

-- ej cumplePredicado esPar [2, 3, 4, 5]



--b) list 
-- resive dos listas y devuelve una lista con los elementos en comun de las listas

elementosEnComun xs ys = [x | x <- xs, x `elem` ys]

-- elementosEnComun :: Eq a => [a] -> [a] -> [a]
-- elementosEnComun [] _ = []
-- elementosEnComun (x:xs) ys
--     | x `elem` ys = x : elementosEnComun xs ys       -- elem compara cada elemento x con []
--     | otherwise = x elementosEnComun xs ys 

-- ej elementosEnComun [1,2,6,8] [1,3,2]




-- c) realizar con guards ||
-- resive una lista, 2 enteros n c  y devuelve una lista n elementos despues y c elementos siguienetes

subLista lista 0 0 = []
subLista (x:xs) n c
    | n == 0 && c == 0 = []
    | n > 0 = subLista xs (n-1) c
    | otherwise = x : subLista xs n (c-1) 
-- ej: subLista [1, 2, 3, 4] 2 2


-- nPrimerosBorrar :: Eq a => [a] -> n -> c -> [a]
nPrimerosBorrar (x:xs) n  
    | n == 0 = (x:xs)
    | otherwise = nPrimerosBorrar xs (n-1)
-- ej: nPrimerosBorrar [1, 2, 3, 4] 2

-- cPrimeros :: Eq a => [a] -> n -> c -> [a]
cPrimeros (x:xs) c  
    | c == 0 = []
    | otherwise = x : cPrimeros xs (c-1)
-- ej: cPrimeros [1, 2, 3, 4] 2



