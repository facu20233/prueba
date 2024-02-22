% a. Dado un número natural n se pueda:
% i. Escribir los primeros n números pares.
%rCaso base: para n igual a 0, la lista resultante es vacía.
primerosNumerosPares(0, []). 
primerosNumerosPares(N, [H|T]):- 
    N > 0,
    H is N * 2,
    N1 is N - 1,
    primerosNumerosPares(N1, T),
    write(T).

% ii. Calcular la suma de sus dígitos, no lo entiendo
sumaDigitos(0, 0).
sumaDigitos(N, Suma):-
    N > 0,
    Digito is N mod 10, %resto
    N1 is N // 10, %cociente
    sumaDigitos(N1, SumaRestante),
    Suma is SumaRestante + Digito,
    write(SumaRestante).
    
    

%iii. Encontrar el digito de mayor valor.
% Regla para encontrar el dígito de mayor valor en un número
digitoMayorValor(Numero, DigitoMayor) :-
    atom_chars(Numero, ListaCaracteres),   % lista caracteres
    convertirAEnteros(ListaCaracteres, ListaEnteros),  %lista entero
    max_list(ListaEnteros, DigitoMayor).  %max

% Regla auxiliar para convertir una lista de caracteres a una lista de enteros
convertirAEnteros([], []).
convertirAEnteros([H|T], [Entero|Resto]) :-
    atom_number(H, Entero),
    convertirAEnteros(T, Resto). %noseeeeeee

%i. Crear una lista con los n primeros números naturales.
nPrimerosNaturales(0, []).
nPrimerosNaturales(N, [N|Resto]) :-
    N > 0,
    N1 is N - 1,
    nPrimerosNaturales(N1, Resto).

% ii. Eliminar de la lista todos los elementos iguales a un valor dado.
% eliminarElemento(2, [1, 2, 3, 2, 4, 2, 5], Resultado).
eliminarElemento(_, [], []).

eliminarElemento(Elemento, [Elemento|T], Resultado) :-
    eliminarElemento(Elemento, T, Resultado).

eliminarElemento(Elemento, [H|T], [H|Resultado]) :-
    H \= Elemento, 
    eliminarElemento(Elemento, T, Resultado).



