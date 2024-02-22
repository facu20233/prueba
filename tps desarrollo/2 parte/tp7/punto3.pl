%a. Una base de conocimiento adecuada.
%persona(nombre, edad, estado_civil).
persona(luis, 20, soltero).
persona(juan, 72, viudo).
persona(pedro, 40, casado).
persona(julia, 17, casada).
persona(maria, 46, soltera).
persona(andres, 50, casado).
persona(rocio, 67, soltera).

persona(joaquin, 15, soltero).
persona(cecilia, 35, soltera).
persona(felicia, 60, soltera).
persona(santiago, 45, casado).
persona(veronica, 34, casada).
persona(eugenia, 70, viuda).
persona(carlos, 73, casado).

%b. Las reglas para encontrar las personas menores de edad.
menorDeEdad(Nombre):- 
    persona(Nombre, Edad, Estado),
    Edad < 18.

%c. Las reglas para encontrar a todas las personas que están en condiciones de acceder a la jubilación
jubilacion(Nombre):- 
    persona(Nombre, Edad, Estado), 
    Edad >= 60.

%d Una regla que le permita establecer la relación X es mayor que Y
mayorQue(PersonaX, PersonaY):-
    persona(PersonaX, EdadX, Estado), 
    persona(PersonaY, EdadY, Estado), 
    EdadX > EdadY.

%e. Una regla para determinar quiénes son coetáneos, menos de 10 años de diferencia de edad 
%m.
coetaneos(PersonaX, PersonaY):- 
    persona(PersonaX, EdadX, Estado), 
    persona(PersonaY, EdadY, Estado), 
    (EdadX - EdadY) < 10.

% menos de 10 años de diferencia de edad
coetaneos(PersonaX, PersonaY):- 
    persona(PersonaX, EdadX, Estado), 
    persona(PersonaY, EdadY, Estado), 
    abs(EdadX - EdadY) < 10.
