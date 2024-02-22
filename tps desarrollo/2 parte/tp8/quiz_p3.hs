-- -- Definición de la función misterio
-- misterio :: (Ord a) => [a] -> a -> a -> [a]
-- misterio xs a b
--   | null xs = []
--   | a <= head xs && head xs <= b = [head xs] ++ misterio (tail xs) a b
--   | otherwise = misterio (tail xs) a b

-- -- Ejemplo de uso
-- main :: IO ()
-- main = do
--   let listaEjemplo = [1, 2, 3, 4, 5, 6, 7, 8, 9]
--       a = 3
--       b = 7
--       resultado = misterio listaEjemplo a b

--   putStrLn $ "Lista de ejemplo: " ++ show listaEjemplo
--   putStrLn $ "Valor de a: " ++ show a
--   putStrLn $ "Valor de b: " ++ show b
--   putStrLn $ "Resultado de misterio: " ++ show resultado  -- Agrega esta línea

-- Definición de la función misterio
-- misterio :: (Ord a) => [a] -> a -> a -> [a]
-- misterio [] _ _ = [] -- Caso base: lista vacía
-- misterio (x:xs) a b =
--   (if a <= x && x <= b then [x] else []) ++ misterio xs a b

-- -- Ejemplo de uso
-- main :: IO ()
-- main = do
--   let listaEjemplo = [1, 2, 3, 4, 5, 6, 7, 8, 9]
--       a = 3
--       b = 7
--       resultado = misterio listaEjemplo a b

--   putStrLn $ "Lista de ejemplo: " ++ show listaEjemplo
--   putStrLn $ "Valor de a: " ++ show a
--   putStrLn $ "Valor de b: " ++ show b
--   putStrLn $ "Resultado de misterio: " ++ show resultado

-- Definición de la función misterio
misterio :: (Ord a) => [a] -> a -> a -> [a]
misterio xs a b = [x | x <- xs, a <= x, x <= b]

-- Ejemplo de uso
main :: IO ()
main = do
  let listaEjemplo = [1, 2, 3, 4, 5, 6, 7, 8, 9]
      a = 3
      b = 7
      resultado = misterio listaEjemplo a b

  putStrLn $ "Lista de ejemplo: " ++ show listaEjemplo
  putStrLn $ "Valor de a: " ++ show a
  putStrLn $ "Valor de b: " ++ show b
  putStrLn $ "Resultado de misterio: " ++ show resultado

