numero(0):-
    write(0). 

numero(N):- --2 ; 
    N1 is N-1, -- N1=1 ; N1=0
    numero(N1), -- numero(1) ; numero(0)
    write(N). -- 2 ; 1 ; write(0)