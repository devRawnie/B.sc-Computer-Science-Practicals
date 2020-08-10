/*
    list: []
    [L]: list represented as different numbers

    [H|T]: Head and Tail, Head is the first element, rest all elements are passed into tail
            all the operations are performed on the head only
    Check an element exists in the list: 

*/

/*q10*/
memb(A,L):-(
    memb(A,L,R),
    R = 1
    ->  write(A), write(" is a member of list"),!
    ;   write(A), write(" is not a member of list"),!
).
memb(H, [H|_], 1).
memb(X, [H|T], R):- 
(
    X = H
    ->R is 1
    ;   (
            memb(X, T, R1),
            R is R1
        )
).

/*length*/
len(L):-len(L,R),write("Length of list is: "),write(R).
len([], 0).
len([_|T], R):- 
(
    len(T, R1),
    R is R1 + 1
).
/*append*/
append(X, L):-conc([X],L,R), print(R).
% append(X, L):-conc([X],L,R), print(R).
/* q11 concatenate */
conc(A,B):-conc(A,B,R),write("concatenated list is: "),write(R),!.
conc([], X, X).
conc(X, [], X).
conc([H1|T1], L2, [H1|T3]):- conc(T1, L2, T3).
/* q12 reverse */
rev(X):-rev(X,R),write("reversed list is: "),write(R).
rev(X, R):-rev(X,[],R).
rev([], X, X).
rev([H1|T1], PREV, REV):-rev(T1, [H1|PREV], REV).
/*equals*/
equals([], []):-print("yes").
equals([H1|T1],[H2|T2]):-
(
    H1 = H2
    -> equals(T1, T2)
    ; print("no")
).

/* q13 TODO palindrome 
palindrome(A):-rev(A,R), equals(A,R).*/
palindrome(A):-rev(A,R), A = R.
/* q14 sum of list */
lsum(L):-lsum(L,S),write("sum of list is: "),write(S).
lsum([], 0).
lsum([H|T], R):-
(
    lsum(T, R1),
    R is H + R1
).    
/* q15 even odd methods to check lengths of list*/
evenlength(L):-
(
    len(L, R1),
    0 is mod(R1,2)
).
oddlength(L):-
(
    len(L, R1),
    1 is mod(R1,2)
).
/* q16 print nth element of a list */
nth_element(N, L):-nth_element(N, L, X),write("element at pos "),write(N),write(" is: "),write(X),!.
nth_element(_, [], _):-print("out of bounds"),!.
nth_element(N, [H|T], X):-
(
    N > 0
    ->  (
            N = 1
            ->X is H
            ;   (
                    N1 is N - 1,
                    nth_element(N1, T, X),!
                )
        )
    ; print("Invalid index")
).

/* q17 remove duplicates */
remove_dup(L):-remove_dup(L, R),write("List after removing duplicates is: "),write(R),!.
remove_dup([], []).
remove_dup([H|T], [H|R]):-
(
    delete_all(H, T, R1),
    remove_dup(R1, R)
).
/*q18 maxlist */
maxlist([]):-write("Empty list"),!.
maxlist([H|T]):-maxlist(T, H).
maxlist([H|[]], M):-
(
    M > H
    -> print(M),!
    ; print(H),!
).
maxlist([H|T], M):-
(
    M > H
    ->maxlist(T, M)
    ; maxlist(T, H)    
).

/* q19 insert element x at nth position*/
insert_nth(X, P, L):-insert_nth(X, P, L, R),print(R),!.
insert_nth(X, 1, Y, [X|Y]).
insert_nth(X, P, [H|T], [H|T1]):-
(
    P1 is P - 1,
    insert_nth(X, P1, T, T1)
).

/*q20 sublist*/
sublist([],[]):-print("It is a sublist").
sublist([], [_|_]):-print("It is a sublist").
sublist([_|_], []):-print("Not a sublist").
sublist([H|T], [H1|T1]):-
(
    H = H1
    -> sublist(T, T1)
    ;  sublist([H|T], T1)    
). 
/*q21 delete nth*/
delete_nth(P, L):-delete_nth(P, L,R), print(R),!.
delete_nth(1, [_|T], T).
delete_nth(P, [H|T], [H|T1]):-
(
    P1 is P - 1,
    delete_nth(P1, T, T1)
).

/*q22 
delete_all(X, L, R)
delete all occurrences of X from L to return R
*/
delete_all(X, L):-delete_all(X,L,R),write("List without element "), write(X),write(" is: "),write(R),!.
delete_all(_, [], []).
delete_all(X, [X|T], L):-delete_all(X, T, L).
delete_all(X, [H|T], [H|T1]):-delete_all(X, T, T1).

/*q23 merge(L1,L2,L3)*/
merge(X, Y):-merge(X, Y, R), write("Merged list is: "),write(R),!.
merge([], X, X).
merge(X, [], X).
merge([H1|T1], [H2|T2], [X|R]):-
(
    H1 < H2
    ->  X is H1,
        merge(T1, [H2|T2], R)
    ;   X is H2,
        merge([H1|T1], T2, R)
).