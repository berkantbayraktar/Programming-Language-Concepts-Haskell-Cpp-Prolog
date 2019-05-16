:- module(hw5,[catomic_number/2, ion/2, molecule/2]).
:- [catoms].

sum([],0).

sum([Head | Tail], Sum) :-
    sum(Tail, SumTail),
    Sum is SumTail + Head.

getCharge(El,Charge) :-
    El =< 4 -> Charge is El.

getCharge(El,Charge):-
    El > 4 -> Charge is (El - 8).

catomic_number(Name, Catomic_Number) :-
    catom(Name,_, _, A),
    sum(A,Catomic_Number).

ion( Name , Charge ):-
    catom(Name,_, _, L),
    last(L,Last),
    getCharge(Last,Charge).

molecule(Catom_List, Total_Catomic_Number) :-
    Total_Catomic_Number is 5.