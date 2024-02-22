abuelo(jamesSirius, jamesPotter). %abuelo
abuelo(albusSeverus, jamesPotter). %abuelo
abuelo(lilyLuna, jamesPotter). %abuelo
abuelo(jamesSirius, lilyEvans). %abuelaa
abuelo(albusSeverus, lilyEvans). %abuelaa
abuelo(lilyLuna, lilyEvans). %abuelaa
%abuelo der
%implementar

%masculino
masculino(jamesPotter).
masculino(arthurWeasley).
%implementar restantes
%femenino
femenino(lilyEvans).
femenino(mollyWeasley).
%implementar restantes


----------------------------------------------
%masculino
masculino(jamesPotter).
masculino(arthurWeasley).
%implementar restantes
%femenino
femenino(lilyEvans).
femenino(mollyWeasley).
%implementar restantes

-----------------------
%bien
%hermanos rose hugo
hermano(X, Y):- 
    progenitor(Z, X),
    progenitor(Z, Y),
    X \= Y, 
    masculino(X).

%bien
%primos los de abajo
primo(X, Y):- 
    progenitor(Z, X),
    progenitor(W, Y), 
    hermano(Z, W),
    X \= Y, masculino(X).

    prima(X, Y):- 
    progenitor(Z, X), 
    progenitor(W, Y), 
    hermana(Z, W), 
    X \= Y, 
    femenino(X).

%bisabueloDe B ct
bisabueloDe(Bisabuelo, Nieto) :-
    progenitor(Nieto, Hijo),
    abuelo(Bisabuelo, Hijo).

----------------------------------

%producto 2 70& descuento B
promoSemanal(Producto1, Producto2):-
    producto(Categoria, Producto1),
    producto(Categoria, Producto2),
    precio(Producto1, Precio1),
    precio(Producto2, Precio2),
    Precio1 > Precio2,
    PrecioPromedio is (Precio1 + Precio2) / 2,
    categoriaValida(Categoria),
    PrecioPromedio < 200.