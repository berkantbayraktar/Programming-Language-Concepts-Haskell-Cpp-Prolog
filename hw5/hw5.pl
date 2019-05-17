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


memberX(El, [H | T]) :- 
    El = H;
    member(El,T).

ionic_pair(A,B,Number):-
    ion(A,ChargeA), ion(B,ChargeB),
    S is ChargeA + ChargeB, S = 0,
    catomic_number(A,CatomicA), catomic_number(B,CatomicB),
    Total is CatomicA + CatomicB, Total = Number.


molecule(Catom_List, Total_Catomic_Number) :-
    moleculess(Catom_List,Total_Charge,Total_Catomic_Number),
    sum(Total_Charge,Summation),
    Summation = 0.
  

moleculess(Catom_List,T,0) :-
    T = [],
    Catom_List = [].
moleculess(Catom_List,T,Total_Catomic_Number) :-
    between(0,Total_Catomic_Number,N),
    N1 is Total_Catomic_Number - N,
    catomic_number(Neym,N1),
    ion(Neym,C),
    Rest is Total_Catomic_Number - N1,
    moleculess(Rest_List,R_T,Rest),
    T = [C| R_T],
    Catom_List = [Neym | Rest_List].