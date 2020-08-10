node(p).
node(q).
node(r).
node(s).
node(t).
edge(p,q).
edge(q,r).
edge(r,q).
edge(q,s).
edge(s,t).
path(X,Y,R):-
(   
    node(X),
    node(Y),
    X \= Y
    ->  (
            edge(X,Y)
            ->  R is 1
            ;   (
                    edge(X,Z),
                    Y \= Z,
                    path(Z,Y, R2),
                    R2 = 1
                    ->  R is 1
                    ;   R is 0
                )  
        )
    ; R is 0
).