% Definición de la estructura del ADT LISTA
% Se utiliza una lista de Prolog para representar la lista.

% Sintaxis
% LISTAVACIA: → LISTA
% INSERTAR: LISTA x item → LISTA
% ESLISTAVACIA: LISTA → bool
% BORRAR: LISTA → LISTA
% PRIMERO: LISTA → item U {indefinido}
% ULTIMO: LISTA → item U {indefinido}
% PERTENECE: LISTA x item → bool

% Definición de las reglas
es_lista_vacia([]).

insertar(L, X, [X|L]).

es_lista_vacia([]).
es_lista_vacia([_|_]).

borrar([], []).
borrar([_|T], T).

primero([], indefinido).
primero([X|_], X).

ultimo([], indefinido).
ultimo([X], X).
ultimo([_|T], U) :- ultimo(T, U).

pertenece([], _, false).
pertenece([X|_], X, true).
pertenece([_|T], K, R) :- pertenece(T, K, R).

% Operación adicional
longitud([], 0).
longitud([_|T], N) :- longitud(T, N1), N is N1 + 1.
