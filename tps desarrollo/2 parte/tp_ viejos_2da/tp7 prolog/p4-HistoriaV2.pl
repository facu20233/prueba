% − Tía Agatha, el mayordomo y Charles son las únicas personas que viven en la mansión Dreadbury.
viveEnMansion(tiaAgatha).
viveEnMansion(mayordomo).
viveEnMansion(charles).

% − Charles odia a todas las personas de la mansión que no son odiadas por la tía Agatha.
odia(charles, Victima):-
    viveEnMansion(Victima),
    \+ odia(tiaAgatha, Victima),
    Victima \= charles. 

% − Agatha odia a todos los que viven en la mansión, excepto al mayordomo.
odia(tiaAgatha, Persona) :-
    viveEnMansion(Persona),
    Persona \= mayordomo,
    Persona \= tiaAgatha. 

% − El mayordomo odia a las mismas personas que odia tía Agatha.
odia(mayordomo, Persona) :-
    odia(tiaAgatha, Persona),  
    viveEnMansion(Persona),
    Persona \= mayordomo. 

% − Quien no es odiado por el mayordomo y vive en la mansión, es más rico que tía Agatha
esMasRicoQue(tiaAgatha, Persona) :-
    \+ odia(mayordomo, Persona),
    viveEnMansion(Persona),
    Persona \= tiaAgatha.

% − Un asesino siempre odia a su víctima y nunca es más rico que ella. Además, el asesino
asesino(Asesino, Victima) :-
    odia(Asesino, Victima),
    \+ esMasRicoQue(Asesino, Victima),
    viveEnMansion(Asesino).

    





