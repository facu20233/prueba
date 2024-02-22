-- -- Definición de la función f
f :: (a -> b) -> Int -> [a] -> [b]
f h a xs
  | null xs = []
  | a <= 0 = []
  | otherwise = h (head xs) : f h (a - 1) (tail xs)

-- Ejemplo de uso
main :: IO ()
main = do
  let cuadrado x = x-1
      listaEjemplo = [1, 2, 3, 4, 5]
      a = 10
      resultado = f cuadrado a listaEjemplo

  putStrLn $ "Lista de ejemplo: " ++ show listaEjemplo
  putStrLn $ "Valor de a: " ++ show a
  putStrLn $ "Resultado de f: " ++ show resultado


