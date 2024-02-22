-- 1. Explique qué hace el siguiente código Haskell y de un nombre más adecuado a la función.misterio :: Int -> Int -> Int
misterio x y
    | (x < y) = 0
    | otherwise = 1 + misterio (x - y) y

-- 2. Implemente una función que, dados a y b calcule ab.
potencia :: Int -> Int -> Int
potencia a b
    | b == 0    = 1
    | otherwise = a * potencia a (b - 1)

-- 3. Escriba en Haskell una función que cuente cuantas veces se repite un elemento en una lista.
contarRepeticiones :: Eq a => a -> [a] -> Int
contarRepeticiones _ [] = 0
contarRepeticiones x (y:ys)
    | x == y    = 1 + contarRepeticiones x ys
    | otherwise = contarRepeticiones x ys

-- 4. Implemente una función que devuelva una lista formada por el segundo argumento tantas veces como lo indique el primer argumento.
replicar :: Int -> a -> [a]
replicar n x
    | n <= 0    = []
    | otherwise = replicate n x 

-- 5. Implemente una función que permita retornar los primeros n elementos de una lista.
primerosN :: Int -> [a] -> [a]
primerosN n lista
    | n <= 0    = []
    | otherwise = take n lista

-- 6. Escriba una función: que reciba otra función como primer parámetro y un segundo parámetro que actúe como argumento de la función recibida. Defina la función para que el resultado sea una doble aplicación de la función pasada por parámetro con el segundo argumento.

dobleAplicacion :: (a -> a) -> a -> a
dobleAplicacion f x = f (f x)

duplicar :: Int -> Int
duplicar y = y*2

cuadrado :: Int -> Int
cuadrado x = x*x

esMayorQue0 :: Int -> Bool
esMayorQue0 n = x > 0

esPar :: Int -> Bool
esPar n = n `mod` 2 == 0

duplicarLista :: Num a => [a] -> [a]
duplicarLista lista = map (*2) lista


-- 7. Escriba una función que combine dos listas aplicando otra función que reciba como parámetro un elemento de cada lista a combinar por vez. Utilice la siguiente definición de tipo para su función:
-- combinarCon :: (a -> b -> c) -> [a] -> [b] -> [c]
combinarCon :: (a -> b -> c) -> [a] -> [b] -> [c]
combinarCon _ [] _ = []
combinarCon _ _ [] = []
combinarCon f (x:xs) (y:ys) = f x y : combinarCon f xs ys
-- combinarCon (+) [1, 2, 3] [4, 5, 6]
-- combinarCon (\a b -> duplicar a) [1, 2, 3, 4] [1, 2, 3, 4]

-- 8. En un párrafo explique qué hace el siguiente código Haskell y dé un nombre más adecuado a la función. También explique cómo se usa dicha función mediante un ejemplo y muestre la aplicación de la función en cada paso de recursión.
misterio2 :: Int -> [a] -> ([a], [a])
-- partir
misterio2 _ [] = ([], [])
misterio2 n l@(x : xs)
    | n > 0 = (x : ys, zs)
    | otherwise = ([], l)
    where (ys,zs) = misterio2 (n - 1) xs

-- 9. Defina una función m: que reciba como parámetros una función f de un argumento y una lista y devuelva como resultado la lista recibida en la que cada uno de sus elementos haya sido transformado con la función f.
m :: (a -> b) -> [a] -> [b]
m _ [] = []   -- Caso base: la lista vacía se mapea a la lista vacía
m f (x:xs) = f x : m f xs  -- Aplicar la función a cada elemento y recursión sobre el resto de la lista

-- 10. Explique qué hace la siguiente función. Rescribirla con nombres de identificadores significativos.
-- cumplir condicion de la funcion
-- cumple agrega
cumpleCondicion :: (a -> Bool) -> [a] -> [a]
cumpleCondicion _ [] = []
cumpleCondicion p (x:xs)
    | p x = x : cumpleCondicion p xs
    | otherwise = cumpleCondicion p xs  