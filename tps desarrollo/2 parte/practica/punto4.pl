%Base de Conocimiento ALMACEN DON MANOLO
%producto(Tipo, producto)

producto(lacteo, leche).
producto(lacteo, manteca).
producto(lacteo, crema).
producto(lacteo, yogurt).

producto(fiambre, queso).
producto(fiambre, jamonCrudo).
producto(fiambre, jamonCocido).
producto(fiambre, salame).

producto(panaderia, pan).
producto(panaderia, factura).
producto(panaderia, tortilla).
producto(panaderia, galleta).

producto(bebida, agua).
producto(bebida, gaseosa).
producto(bebida, jugo).
producto(bebida, soda).

producto(golosina, chocolate).
producto(golosina, caramelo).
producto(golosina, mantecol).
producto(golosina, bombones).
producto(golosina, nugaton).

precio(leche, 77).
precio(manteca, 62).
precio(crema, 95).
precio(yogurt, 53).
precio(queso, 80).

precio(jamonCrudo, 170).
precio(jamonCocido, 100).
precio(salame, 85).

precio(pan, 80).
precio(factura, 20).
precio(tortilla, 10).
precio(galleta, 75).

precio(agua, 86).
precio(gaseosa, 130).
precio(jugo, 98).
precio(soda, 100).

precio(chocolate, 116).
precio(caramelo, 35).
precio(mantecol, 87).
precio(bombones, 140).
precio(nugaton, 51).

% a. Escriba una regla en Prolog que le permita obtener todas los lácteos cuyo precio es mayor que un dado valor.
lacteosConPrecioMayorA(Producto, PrecioX):- 
    producto(lacteo, Producto), %constante
    precio(Producto, Precio), 
    PrecioX < Precio.

%nota 2 reglas
%lacteo(x)
%precio(x,R) 

% b. Escriba una regla en Prolog que permita determinar los productos que entran en la PROMO SEMANAL.
% PROMO el 2do al 70%: Lleve 2 productos y el 2do con un 70% de descuento. Condiciones: los productos de la promoción deben pertenecer a la misma categoría y el promedio de precios debe ser menor que $200. En ese caso, el cliente lleva los 2 y paga el producto de menor valor con un 70% de descuento
%version 2


productosPromo(Producto1, Producto2, Apagar):-  
    % categ
    producto(Categoria, Producto1),
    producto(Categoria, Producto2),
    % promed
    producto(Producto1, Precio1),
    producto(Producto2, Precio2),
    Promedio is (Precio1 + Precio2)/2,
    Promedio < 200,
    Apagar is descuento(Producto1, Producto2, DescuentoT).

descuento(Producto1, Producto2, DescuentoT):-
    producto(Producto1, Precio1),
    producto(Producto2, Precio2),
    Precio2 is Precio2*07,
    DescuentoT is Precio1 + Precio2.

categoria(Producto1, Producto2):-
    producto(Categoria, Producto1),
    producto(Categoria, Producto2).