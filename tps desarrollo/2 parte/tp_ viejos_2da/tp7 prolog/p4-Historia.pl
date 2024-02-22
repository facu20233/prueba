% Hechos
vive_en_mansion(tia_agatha).
vive_en_mansion(mayordomo).
vive_en_mansion(charles).

odia(aquien(charles, Quien), mansion_dreadbury) :- 
    vive_en_mansion(Quien), 
    Quien \= tia_agatha.

odia(aquien(tia_agatha, Quien), mansion_dreadbury) :- 
    vive_en_mansion(Quien), 
    Quien \= mayordomo.

es_mas_rico_que(Quien, tia_agatha) :- 
    vive_en_mansion(Quien), 
    not(odia(aquien(mayordomo, Quien), mansion_dreadbury)).

odia(aquien(mayordomo, Quien), mansion_dreadbury) :- 
    odia(aquien(tia_agatha, Quien), mansion_dreadbury).

% Reglas
asesino(X) :-
  vive_en_mansion(X),
  odia(aquien(X, tia_agatha), mansion_dreadbury),
  not(es_mas_rico_que(X, tia_agatha)).

odia(charles, Quien) :- 
    vive_en_mansion(Quien), 
    Quien \= tia_agatha, 
    not(odia(aquien(tia_agatha, Quien), mansion_dreadbury)).

odia_a_agatha(Quien) :- 
    odia(aquien(Quien, tia_agatha), mansion_dreadbury).

odiados_y_sus_odiados :-
  odia(aquien(Persona, Odiado), mansion_dreadbury),
  write(Persona), write(' odia a '), write(Odiado), nl,
  fail.

potencial_asesino_del_mayordomo(X) :-
  vive_en_mansion(X),
  odia(aquien(X, mayordomo), mansion_dreadbury),
  not(odia(aquien(tia_agatha, X), mansion_dreadbury)).
