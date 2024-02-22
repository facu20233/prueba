%reglas
%predicado(arg1, arg2) - true , me devuelve arg
%relacion(obj1, obj2)

% inventado bisabuelo
progenitor(jamesPotter, jamesPotter1). 

%james 
%progenito(hijo, padre/madre)
progenitor(harry, jamesPotter). 
progenitor(harry, lilyEvans).  

%arthur 
progenitor(ginny, arthurWeasley). 
progenitor(fred, arthurWeasley).
progenitor(george, arthurWeasley).
progenitor(ron, arthurWeasley).
progenitor(ginny, mollyWeasley).
progenitor(fred, mollyWeasley).
progenitor(george, mollyWeasley).
progenitor(ron, mollyWeasley).

%harry
progenitor(jamesSirius, harry).
progenitor(albusSeverus, harry).
progenitor(lilyLuna, harry).
progenitor(jamesSirius, ginny).
progenitor(albusSeverus, ginny).
progenitor(lilyLuna, ginny).

%ron
progenitor(rose,ron).
progenitor(hugo,ron).
progenitor(rose,hermione).
progenitor(hugo,hermione).

%abuelxs
abuelxs(Nieto, Abuelo):- 
    progenitor(Nieto, Padre),
    progenitor(Padre, Abuelo).

%masculino
masculino(jamesPotter).
masculino(arthurWeasley).
masculino(harry).
masculino(fred).
masculino(george).
masculino(ron).
masculino(jamesSirius).
masculino(albusSeverus).
masculino(hugo).

%femenino
femenino(lilyEvans).
femenino(mollyWeasley).
femenino(ginny).
femenino(hermione).
femenino(lilyLuna).
femenino(rose).

%padres 
%https://onedrive.live.com/redir?resid=4CE1D141F609DEA7%212567&page=Edit&wd=target%28Paradigmas%2Ftps.one%7Cd0b136da-6ca9-45fc-805f-4515a451b5f0%2FP%C3%A1gina%20sin%20t%C3%ADtulo%7C69259744-2ef7-446c-9067-6c8646a7afc7%2F%29&wdorigin=NavigationUrl

padreDe(Hijx, Padre):-
    progenitor(Hijx, Padre), 
    masculino(Padre).

madreDe(Hijx, Madre):- 
    progenitor(Hijx, Madre),
    femenino(Madre).

%hijos
hijo(Hijo, Padrx):- 
    progenitor(Hijo, Padrx),
    masculino(Hijo). %hijo?


hija(Hija, Padrx):- 
    progenitor(Hija, Padrx), 
    femenino(Hija). 

%abuelo 
abuelo(Nietx, Abuelo):- 
    progenitor(Nietx, Padre),
    progenitor(Padre, Abuelo),
    masculino(Abuelo).

%hermanos
hermanX(Hermano1, Hermano2):- 
    madreDe(Hermano2, Madre), %madreyPadre
    madreDe(Hermano1, Madre), 
    Hermano2 \= Hermano1. 

hermano(Hermano1, Hermano2):- 
    madreDe(Hermano2, Madre), %madreyPadre
    madreDe(Hermano1, Madre), 
    Hermano1 \= Hermano1, 
    masculino(Hermano2).

hermana(Hermano, Hermana2):- 
    madreDe(Hermana2, Madre), %madreyPadre
    madreDe(Hermano, Madre), 
    Hermano \= Hermana2, 
    femenino(Hermana2).

%primos los de abajo
primo(Primo, Primo2):- 
    progenitor(Primo, Padrx1),
    progenitor(Primo2, Padrx2), 
    hermanX(Padrx1, Padrx2),
    Primo \= Primo2,
    masculino(Primo2).

prima(X, Y):-  %corregir
    progenitor(Z, X), 
    progenitor(W, Y), 
    hermana(Z, W), 
    X \= Y, 
    femenino(X).

%tios B
tio(Sobrino, Tio):- 
    progenitor(Sobrino, Padrx), 
    hermanX(Tio, Padrx), 
    masculino(Tio).

tia(X, Y):- %corregir
    progenitor(Z, Y), 
    hermana(Z, X), 
    femenino(X).

%bisabueloDe B, revisar
bisabueloDe(Bisabuelo, Nieto):-
    progenitor(Nieto, Padre1),
    progenitor(Padre1, Padre2),
    progenitor(Padre2, Bisabuelo).


 