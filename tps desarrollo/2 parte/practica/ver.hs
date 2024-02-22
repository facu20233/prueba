-- 2c. contarIguales que dada una lista de números enteros y un número X, cuente cuantos elementos de la lista son iguales que X
-- 2,4,2,3 X=2 -> 2
-- contarIguales :: Eq a => a -> [a] -> Int
contarIguales _ [] = 0
contarIguales n (x:xs)
    | x == n = 1 + contarIguales n xs
    | otherwise = contarIguales n xs

-- ej contarIguales 2 [1,2,3,4,2]

-- 2d. eliminarIgualesX que reciba una lista y un número X y elimine de la lista todos los elementos iguales a X. 
eliminarIgualesX _ [] = []
eliminarIgualesX n (x:xs)
    | x == n = eliminarIgualesX n xs
    | otherwise = x : eliminarIgualesX n xs

-- e. listaNaturales que reciba un valor n y devuelva la lista de los primeros n números naturales.
-- i. Realice una versión con guards (or) 
-- listaNaturales :: a -> [a]
listaNaturales n
    | n == 0 = []
    | otherwise = [1..n]

-- ej eliminarIgualesX 2 [1,2,2]

-- ii. Realice una versión con pattern matching (patrones)
listaNaturales1 0 = []
listaNaturales1 n = [1..n]

-- iii. Realice una versión con list comprehension (conjunto) 
listaNaturales2 n = [x | x <- [1..n]]

-- g. diferencia que reciba dos listas y devuelva una nueva lista con los elementos de la primera lista que no están en la segunda lista. 
-- abcd cd -> ab
-- diferencia :: [a] -> [a] -> [a]
diferencia _ [] = []
diferencia [] _ = []
diferencia (x:xs) lista
    | x `elem` lista = diferencia xs lista 
    | otherwise = x : diferencia xs lista 

-- k. combinar que reciba una función f y dos listas y retorne una nueva lista que resulta de la combinación las listas aplicando la función f. La función f debe recibir como parámetro un elemento de cada lista a combinar por vez. Utilice la siguiente definición de tipo para su función: combinarCon :: (a -> b -> c) -> [a] -> [b] -> [c]
-- func lista1 lista2 -> listaR 
combinar :: (a -> b -> c) -> [a] -> [b] -> [c]
combinar f [] _ = []
combinar f _ [] = []
combinar f (x:xs) (y:ys) = f x y : combinar f xs ys

-- l. filtrarLista que reciba un predicado y una lista y luego regresa la lista de elementos que satisfacen el predicado. La signatura de la función debería ser: filtrarLista :: (a -> Bool) -> [a] -> [a]
-- i. Realice una versión con guards 
-- pred lista -> lista
-- filtrarLista :: (a -> Bool) -> [a] -> [a]
filtrarLista _ [] = []
filtrarLista p (x:xs) 
    |  p x = x : filtrarLista p xs
    |  otherwise = filtrarLista p xs

-- ii. Realice una versión con list comprehension
-- filtrarLista _ [] = []
filtrarLista2 p (x:xs) = [x | x <- xs, p x]
