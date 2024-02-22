-- basicos
esPar :: Int -> Bool
esPar n = n `mod` 2 == 0

multiplicarPorDos :: Num a => a -> a
multiplicarPorDos n = n*2


--1. Explique qué hace el siguiente código Haskell y de un nombre más adecuado a la función.
-- 3 4: 3+3+3+3
misterio x y
    | (y==0 || x==0) = 0  -- 0 5
    | x<0 && y<0 = misterio (-x) (-y)  -- 2 negativo
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

-- 2c. contarIguales que dada una lista de números enteros y un número X, cuente cuantos elementos de la lista son iguales que X
-- 2,4,2,3 X=2 -> 2
contarIguales :: a -> [a] -> [a]
contarIguales _ [] = []
contarIguales n (x:xs)
    | n == x = 1 + contarIguales n xs
    | otherwise = contarIguales n xs

-- 2d. eliminarIgualesX que reciba una lista y un número X y elimine de la lista todos los elementos iguales a X. 


-- e. listaNaturales que reciba un valor n y devuelva la lista de los primeros n números naturales.
-- i. Realice una versión con guards (or) 

-- ii. Realice una versión con pattern matching (patrones)

-- iii. Realice una versión con list comprehension (conjunto) 


-- f. subLista que reciba una lista y un número natural n y retorne una lista sin los primeros n elementos de la lista dada. No utilice drop.
-- 2,5,7,3,5 n=2 -> 7,3,5
subLista :: Int -> [a] -> [a]
subLista 0 lista = lista
subLista n (_:xs)
    | n > 0 = subLista (n - 1) xs
subLista _ _ = error "Número negativo no permitido."

-- g. diferencia que reciba dos listas y devuelva una nueva lista con los elementos de la primera lista que no están en la segunda lista. 
-- abcd cd -> ab
diferencia :: Eq a => [a] -> [a] -> [a]
diferencia [] _ = []
diferencia (x:xs) ys
    | x `elem` ys = diferencia xs ys
    | otherwise = x : diferencia xs ys

-- h. transformar que reciba como parámetros una función f (de un argumento) y una lista y devuelva como resultado la lista recibida en la que cada uno de sus elementos haya sido transformado con la función f.
-- func(a->b) lista -> lista
transformar :: (a -> b) -> [a] -> [b]
transformar _ [] = []
transformar f (x:xs) = f x : transformar f xs

-- i. tablaDePares que, dado un número natural n, construya una lista que contenga los números pares que se encuentran en el intervalo [ 0,n]. Use List Comprehension.
-- n -> [0...n]
tablaDePares :: Int -> [Int]
tablaDePares n = [x | x <- [0..n], even x]

-- j. verificar que recibe un predicado p (un predicado es una función que devuelve un valor booleano) y una lista de elementos xs y devuelve True si todos los elementos de la lista satisfacen el predicado, caso contrario retorna False. Realice una versión con Guards
-- pred lista -> bool


-- k. combinar que reciba una función f y dos listas y retorne una nueva lista que resulta de la combinación las listas aplicando la función f. La función f debe recibir como parámetro un elemento de cada lista a combinar por vez. Utilice la siguiente definición de tipo para su función: combinarCon :: (a -> b -> c) -> [a] -> [b] -> [c]
-- func lista1 lista2 -> listaR 
combinarCon :: (a -> b -> c) -> [a] -> [b] -> [c]
combinarCon _ [] _ = []
combinarCon _ _ [] = []
combinarCon f (x:xs) (y:ys) = f x y : combinarCon f xs ys

-- l. filtrarLista que reciba un predicado y una lista y luego regresa la lista de elementos que satisfacen el predicado. La signatura de la función debería ser: filtrarLista :: (a -> Bool) -> [a] -> [a]
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




