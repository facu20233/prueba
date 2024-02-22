clasificarNumero :: (Ord a, Num a) => a -> String
clasificarNumero x
  | x < 0     = "Negativo"
  | x == 0    = "Cero"
  | x > 0     = "Positivo"

categorizarEdad :: Int -> String
categorizarEdad edad
  | edad < 0              = "Edad inválida"
  | edad < 18             = "Menor de edad"
  | edad >= 18 && edad < 65 = "Adulto"
  | otherwise             = "Adulto mayor"

diaDeLaSemana :: Int -> String
diaDeLaSemana dia
  | dia < 1 || dia > 7  = "Día inválido"
  | dia <= 5            = "Día laborable"
  | otherwise           = "Fin de semana"

calificacion :: Int -> String
calificacion puntaje
  | puntaje < 0 || puntaje > 100 = "Puntaje inválido"
  | puntaje >= 90               = "A"
  | puntaje >= 80               = "B"
  | puntaje >= 70               = "C"
  | puntaje >= 60               = "D"
  | otherwise                   = "F"

tipoDeTriangulo :: (Ord a, Num a) => a -> a -> a -> String
tipoDeTriangulo a b c
  | a <= 0 || b <= 0 || c <= 0              = "No es un triángulo válido"
  | a == b && b == c                       = "Triángulo equilátero"
  | a == b || b == c || a == c             = "Triángulo isósceles"
  | a^2 + b^2 == c^2 || b^2 + c^2 == a^2   = "Triángulo rectángulo"
  | otherwise                              = "Triángulo escaleno"


aplicarDescuento :: (Ord a, Num a) => a -> a -> a
aplicarDescuento total edad
  | total >= 100 && edad >= 60  = total * 0.8
  | total >= 100                 = total * 0.9
  | otherwise                    = total

cuadrante :: (Ord a, Num a) => a -> a -> String
cuadrante x y
  | x > 0 && y > 0  = "Primer cuadrante"
  | x < 0 && y > 0  = "Segundo cuadrante"
  | x < 0 && y < 0  = "Tercer cuadrante"
  | x > 0 && y < 0  = "Cuarto cuadrante"
  | otherwise       = "Origen"
