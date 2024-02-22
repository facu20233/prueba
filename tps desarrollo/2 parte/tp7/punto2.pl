%punto2
% -------- TALENTOS ---------
%cantar
talento(juan, cantar).
talento(pedro, cantar).
talento(maria, cantar).

%pintar
talento(juan, pintar).
talento(patricia, pintar).
talento(lucas, bailar).

%escribir
talento(pedro, escribir).
talento(luisa, escribir).
talento(ana, escribir).

%- talentoso: una persona es talentosa si tiene por los menos 2 talentos.
%m. B
talentosoo(Persona):-
    talento(Persona, Talento1),
    talento(Persona, Talento2),
    Talento1 \= Talento2.

% T
tieneTalentos(Persona, Talento1, Talento2):-
    talento(Persona, Talento1),
    talento(Persona, Talento2),
    Talento1 \= Talento2.

talentoso(Persona):-
    tieneTalentos(Persona, Talento1, Talento2),
    Talento1 \= Talento2.

%- semejantes: dos personas son semejantes si poseen el mismo talento.
%m.
semejantes(Persona1, Persona2):-
    talento(Persona1, Talento),
    talento(Persona2, Talento),
    Persona1 \= Persona2.

