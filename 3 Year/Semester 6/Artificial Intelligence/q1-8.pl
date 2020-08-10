/* 15 Jan 2020
# is assignment
# Ex: sum(X,Y):-R is X + Y, write(R)
# write(x): print x on console
# Accumulator variable: 
# sum(X,Y,R):- R is X + Y
read(X).
*/
/* q1 */
sum(X,Y):-R is X + Y,write("sum is: "),write(R).

/* q2 
max(X,Y,M):-
    (
        X>Y,
        M is X
    ).
max(X,Y,M):-
    (
        Y>X,
        M is Y
    ).
*/
/* = for comparison
if else operator 
(if condition) -> (expression for true) ; (expression for false)
*/
max(X,Y):-
    (
        X>Y
    -> print(X) 
    ;  print(Y)
    ).

/* q3: factorial */
factorial(N):- factorial(N, A), print(A),!.
factorial(0,1).
factorial(N,F):-(
    N > 0
    ->  (
            N1 is N-1,
            factorial(N1, F1),
            F is N*F1
        )
    ; print("Not defined"),!
).
/* q4: fibonacci */
generate_fib(N):-generate_fib(N, A), print(A),!.
generate_fib(1,1).
generate_fib(2,1).
generate_fib(N,T):-
(
    N > 0
    ->(
        N1 is N-1,
        N2 is N-2,
        generate_fib(N1, T1),
        generate_fib(N2, T2),
        T is T1 + T2  
        )
    ; print("Not Defined"),!
).

/* q5: gcd */
gcd(A,B):-A1 is abs(A), B1 is abs(B), gcd(A1, B1, N1), print(N1).
gcd(0,B,N):- N is B.
gcd(A,0,N):- N is A.
gcd(A,B,N):-
    (   A = B
        ->  N is A
        ;   (   A > B
                ->  (   N1 is A-B,
                        gcd(N1,B, G),
                        N is G
                    )
                ;   (   N1 is B - A,
                        gcd(A, N1, G),
                        N is G
                    )
            )
    ).

/*
    ! : cut operator, halts execution 
 q6: raise to power */
 power(N, P):- power(N, P, A), print(A),!.
power(1, _, 1).
power(0, _, 0).
power(_, 0, 1).
power(N, P, A):- 
(   
    P > 0
    ->  (
            P1 is P - 1,
            power(N, P1, A1),
            A is N*A1
        )
    ;   (
            P1 is P + 1,
            power(N, P1, A1),
            A is 1/N*A1
        )
        
).

/* q7: multiplication with recursive addition */
multi(X,Y):-multi(X,Y,R), print(R).
multi(0, _, 0).
multi(_, 0, 0).
multi(X,Y,R):-
(   Y > 0
    ->  (
            Y1 is Y - 1,
            multi(X,Y1,R1),
            R is X + R1    
        )
    ;   (
            Y1 is Y + 1,
            multi(X,Y1,R1),
            R is -1*X + R1
        )

).

/*p8 tower of hanoi */
toh(N):-
(
    N < 0
    ->  print("Not defined")
    ;   power(2, N, R),
        R1 is R - 1,
        write("No of steps: "),write(R1),nl,
        toh(N, "a","b","c")
).
toh(1, A,_,C):-write("Move from "),write(A),write(" to "),write(C),nl.
toh(N, A, B, C):-
(
    N1 is N-1,
    toh(N1, A,C,B),
    write("Move from "),write(A),write(" to "),write(C),nl,
    toh(N1, B,A,C)
).