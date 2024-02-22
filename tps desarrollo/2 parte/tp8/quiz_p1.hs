-- ----------------------------------------------

misterio :: (Ord a, Num b) => [a] -> a -> a -> b
misterio xs a b = sum [1 | z <- xs, z < a || b < z]

main :: IO ()
main = do
    let listaEjemplo = [1,2,3,4,5,6,7,8]
        a = 6
        b = 10
        resultado = misterio listaEjemplo a b

    putStrLn $ "Lista de ejemplo: " ++ show listaEjemplo
    putStrLn $ "Valor de a: " ++ show a
    putStrLn $ "Valor de b: " ++ show b
    putStrLn $ "Resultado de misterio: " ++ show resultado