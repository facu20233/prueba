% Asertos para los vértices
vertice(a).
vertice(b).
vertice(c).
vertice(d).
vertice(e).
vertice(f).

% Asertos para las conexiones (arcos)
% i. ¿Existe arco entre b y c?
% arco(b, c).
% ii. ¿Cuales son los vértices alcanzables desde el vértice b?
% arco(b, X).
arco(a, b).
arco(a, c).
arco(b, a).
arco(b, e).
arco(b, d).
arco(c, a).
arco(c, d).
arco(d, b).
arco(d, e).
arco(d, f).
arco(e, b).
arco(e, f).
arco(e, d).
arco(f, e).
arco(f, d).

% - Adyacencia entre dos vértices.
adyacente(X, Y) :- arco(X, Y).

% - Camino de longitud 2 entre dos vértices dados.
camino_longitud_2(X, Y) :- arco(X, Z), arco(Z, Y).

% - Camino de cualquier longitud entre dos vértices.
camino(X, Y) :- arco(X, Y).
camino(X, Y) :- arco(X, Z), camino(Z, Y).
