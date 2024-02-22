longitud :: [a] -> Int
longitud [] = 0
longitud (_:xs) = 1 + longitud xs
Esta función calcula la longitud de una lista.

Reverso de una Lista:


reverso :: [a] -> [a]
reverso [] = []
reverso (x:xs) = reverso xs ++ [x]
Devuelve la lista invertida.

Suma de Elementos de una Lista:


suma :: Num a => [a] -> a
suma [] = 0
suma (x:xs) = x + suma xs
Calcula la suma de los elementos de la lista.

Map: Aplicar una Función a Cada Elemento de una Lista:


duplicar :: Num a => [a] -> [a]
duplicar lista = map (\x -> 2 * x) lista
Duplica cada elemento de la lista.

Filter: Filtrar Elementos que Cumplen una Condición:

numerosPares :: Integral a => [a] -> [a]
numerosPares lista = filter even lista
Filtra los números pares de la lista.

Foldl: Aplicar una Función Binaria a la Izquierda:

sumaAcumulada :: Num a => [a] -> a
sumaAcumulada lista = foldl (\acc x -> acc + x) 0 lista
Calcula la suma acumulada de los elementos de la lista.

Zip: Combinar dos Listas en Pares:

combinarListas :: [a] -> [b] -> [(a, b)]
combinarListas lista1 lista2 = zip lista1 lista2
Combina dos listas en pares.

Take: Tomar los Primeros N Elementos de una Lista:

tomarN :: Int -> [a] -> [a]
tomarN n lista = take n lista

Toma los primeros n elementos de la lista.

Filter: Filtrar Elementos que Cumplen una Condición:

haskell
Copy code
mayoresQueCinco :: (Num a, Ord a) => [a] -> [a]
mayoresQueCinco lista = filter (> 5) lista
Filtra los elementos mayores que cinco de la lista.

Any: Verificar si Alguno Cumple una Condición:

haskell
Copy code
tieneNegativos :: (Num a, Ord a) => [a] -> Bool
tieneNegativos lista = any (< 0) lista
Verifica si hay algún número negativo en la lista.

All: Verificar si Todos Cumplen una Condición:

todosPositivos :: (Num a, Ord a) => [a] -> Bool
todosPositivos lista = all (> 0) lista
Verifica si todos los números son positivos en la lista.

Concat: Concatenar Listas Anidadas:

concatenar :: [[a]] -> [a]
concatenar listas = concat listas
Concatena listas anidadas en una sola lista.

Replicate: Replicar un Elemento N Veces:

replicarN :: Int -> a -> [a]
replicarN n elemento = replicate n elemento
Replica un elemento n veces en una lista.

ZipWith: Combina Dos Listas Usando una Función Binaria:

sumarListas :: Num a => [a] -> [a] -> [a]
sumarListas lista1 lista2 = zipWith (+) lista1 lista2
Combina dos listas sumando elementos correspondientes.

Partition: Dividir una Lista en Dos Según una Condición:

partirLista :: (a -> Bool) -> [a] -> ([a], [a])
partirLista condicion lista = partition condicion lista