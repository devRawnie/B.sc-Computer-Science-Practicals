male(balkishan).
male(shyam).
male(deepak).
male(devraj).
male(rohit).
male(mohit).
female(kanta).
female(manju).
female(rajni).
female(ritu).
female(pallavi).
female(tripti).
female(mitali).
parent(balkishan, shyam).
parent(balkishan, deepak).
parent(balkishan, devraj).
parent(deepak, rohit).
parent(shyam, mohit).
parent(shyam, tripti).
parent(devraj, pallavi).
parent(devraj, mitali).
parent(kanta, shyam).
parent(kanta, deepak).
parent(kanta, devraj).
parent(rajni,rohit).
parent(manju, mohit).
parent(manju, tripti).
parent(ritu, pallavi).
parent(ritu, mitali).
husband(balkishan, kanta).
husband(deepak, rajni).
husband(shyam, manju).
husband(devraj, ritu).
father(X,Y):-male(X), parent(X,Y).
mother(X,Y):-female(X), parent(X,Y).
son(X,Y):-male(X),parent(Y,X).
daughter(X,Y):-female(X),parent(Y,X).
wife(X,Y):-female(X), husband(Y,X).
grandparent(X,Y):-parent(X,Z),parent(Z,Y).
sibling(X,Y):-father(Z,X),father(Z,Y),X \= Y.
cousin(X,Y):-father(A,X),father(B,Y),sibling(A,B).

