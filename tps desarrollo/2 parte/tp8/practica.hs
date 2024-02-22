-- 2a. productoPorSumasSucesivas que reciba dos números naturales realice el producto entre dichos números mediante sumas sucesivas. 
-- 2 3 = 2+2+2
productoPorSumasSucesivas :: Int -> Int -> Int
productoPorSumasSucesivas x y
| y == 0 = 0
| y > 0 = x + productoPorSumasSucesivas x (y - 1)
| otherwise = productoPorSumasSucesivas x (-y) 

productoPorSumasSucesivas x y
| y == 0 = 0
| y > 0 = x + productoPorSumasSucesivas x (y-1)
| otherwise = productoPorSumasSucesivas x (-y)