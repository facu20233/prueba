-- basicos
esPar :: Int -> Bool
esPar x = x `mod` 2 == 0

multiplicarPorDosL :: Num a => [a] -> [a]
multiplicarPorDosL lista = [x * 2 | x <- lista]

multiplicarPorDos :: Num a => a -> a
multiplicarPorDos x = 2 * x

esIgual :: Eq a => a -> a -> Bool
esIgual x y = x == y


--1. Explique qué hace el siguiente código Haskell y de un nombre más adecuado a la función.
-- 3 4: 3+3+3+3
misterio x y
    | (y==0 || x==0) = 0  -- 0 
    | x<0 && y<0 = misterio (-x) (-y)  -- los hace positivo
    | y<0 = misterio y x  -- 1 es negativo lo invierte
    | otherwise = x + misterio x (y - 1) -- e.o.c suma x + recur

-- 2a. productoPorSumasSucesivas que reciba dos números naturales realice el producto entre dichos números mediante sumas sucesivas. 
-- 2 3 = 2+2+2
productoPorSumasSucesivas :: Int -> Int -> Int
productoPorSumasSucesivas x y
    | y == 0 = 0
    | y > 0 = x + productoPorSumasSucesivas x (y - 1)
    | otherwise = productoPorSumasSucesivas x (-y) 

-- 2b. sumarDigitos que reciba un número positivo y devuelva la suma de sus dígitos
-- 12 -> 3
sumarDigitos :: Int -> Int
sumarDigitos 0 = 0
sumarDigitos n = (n `mod` 10) + sumarDigitos (n `div` 10)
-- https://onedrive.live.com/redir?resid=4CE1D141F609DEA7%212567&page=Edit&wd=target%28Paradigmas%2Ftps.one%7Cd0b136da-6ca9-45fc-805f-4515a451b5f0%2FP%C3%A1gina%20sin%20t%C3%ADtulo%7Cf5cce7a0-1868-4efe-bf79-58eae64b7f61%2F%29&wdorigin=NavigationUrl

-- 2c. contarIguales que dada una lista de números enteros y un número X, cuente cuantos elementos de la lista son iguales que X
-- (2,4,2,3) 2 -> 2
contarIguales :: Eq a => [a] -> a -> Int
contarIguales [] _ = 0
contarIguales (x:xs) e -- lista
    | x == e = 1 + contarIguales xs e
    | otherwise = contarIguales xs e

-- 2d. eliminarIgualesX que reciba una lista y un número X y elimine de la lista todos los elementos iguales a X. 
eliminarIgualesX :: Eq a => [a] -> a -> [a]
eliminarIgualesX [] _ = [] 
eliminarIgualesX (x:xs) e
    | x == e = eliminarIgualesX xs e
    | otherwise = x : eliminarIgualesX xs e -- agrega a la listaR

-- e. listaNaturales que reciba un valor n y devuelva la lista de los primeros n números naturales.
-- i. Realice una versión con guards (or) 
listaNaturalesG :: Int -> [Int]
listaNaturalesG n
    | n <= 0 = []
    | otherwise = [1..n]

-- ii. Realice una versión con pattern matching (patrones)
listaNaturalesM :: Int -> [Int]
listaNaturalesM 0 = []
listaNaturalesM n = [1..n]

-- iii. Realice una versión con list comprehension (conjunto) 
listaNaturalesL :: Int -> [Int]
listaNaturalesL n = [x | x <- [1..n]]

-- f. subLista que reciba una lista y un número natural n y retorne una lista sin los primeros n elementos de la lista dada. No utilice drop.
-- borra n primeros
-- 2,5,7,3,5 n=2 -> 7,3,5
subLista :: Int -> [a] -> [a]
subLista 0 lista = lista -- n == 0 recien tira la lista
subLista n (_:xs)
    | n > 0 = subLista (n - 1) xs
-- subLista _ _ = error "Número negativo no permitido."

-- g. diferencia que reciba dos listas y devuelva una nueva lista con los elementos de la primera lista que no están en la segunda lista. 
-- elementos no tienen en comun
-- abcd cd -> ab
diferencia :: Eq a => [a] -> [a] -> [a]
diferencia [] _ = []
diferencia (x:xs) ys
    | x `elem` ys = diferencia xs ys        -- elem x = lista
    | otherwise = x : diferencia xs ys      -- "":"" agrega el elemnt a la lista

-- h. transformar que reciba como parámetros una función f (de un argumento) y una lista y devuelva como resultado la lista recibida en la que cada uno de sus elementos haya sido transformado con la función f.
-- func(a->b) lista -> lista
transformar :: (a -> b) -> [a] -> [b]
transformar _ [] = []
transformar f (x:xs) = f x : transformar f xs       -- los agrega transforamados a la lista

-- i. tablaDePares que, dado un número natural n, construya una lista que contenga los números pares que se encuentran en el intervalo [ 0,n]. Use List Comprehension.
-- n -> [0...n]
tablaDePares :: Int -> [Int]
tablaDePares n = [x | x <- [0..n], even x]      -- even filtra pares true false

-- j. verificar que recibe un predicado p (un predicado es una función que devuelve un valor booleano) y una lista de elementos xs y devuelve True si todos los elementos de la lista satisfacen el predicado, caso contrario retorna False. Realice una versión con Guards
-- cumple con la condicion
-- P [2,4,6] -> bool ej  todos pares
verificar :: (a -> Bool) -> [a] -> Bool 
verificar _ [] = True
verificar p (x:xs)
    | p x = verificar p xs
    | otherwise = False

-- k. combinar que reciba una función f y dos listas y retorne una nueva lista que resulta de la combinación las listas aplicando la función f. La función f debe recibir como parámetro un elemento de cada lista a combinar por vez. Utilice la siguiente definición de tipo para su función: combinarCon :: (a -> b -> c) -> [a] -> [b] -> [c]
-- func lista1 lista2 -> listaR 
combinarCon :: (a -> b -> c) -> [a] -> [b] -> [c]
combinarCon _ [] _ = []
combinarCon _ _ [] = []
combinarCon f (x:xs) (y:ys) = f x y : combinarCon f xs ys   -- funcion 2 parametros tenes que hacer

-- l. filtrarLista que reciba un predicado y una lista y luego regresa la lista de elementos que satisfacen el predicado. La signatura de la función debería ser: filtrarLista :: (a -> Bool) -> [a] -> [a]

-- x. Realice una versión con pattern
-- pred lista -> lista
filtrarListaP :: (a -> Bool) -> [a] -> [a]
filtrarListaP _ [] = []
filtrarListaP p (x:xs) = if p x then x : filtrarListaP p xs
                        else filtrarListaP p xs

-- i. Realice una versión con guards 
-- pred lista -> lista
filtrarListaG :: (a -> Bool) -> [a] -> [a]
filtrarListaG _ [] = []
filtrarListaG p (x:xs)
    | p x = x : filtrarListaG p xs
    | otherwise = filtrarListaG p xs

-- ii. Realice una versión con list comprehension
filtrarListaL :: (a -> Bool) -> [a] -> [a]
filtrarListaL p xs = [x | x <- xs, p x]




-- ------------ PARCIAL   ------------

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