:- module(hw5,[catomic_number/2, ion/2, molecule/2]).
:- [catoms].

getCharge(El,Charge) :-
    El =< 4 -> Charge is El.

getCharge(El,Charge):-
    El > 4 -> Charge is (El - 8).

catomic_number(Name, Catomic_Number) :-
    catom(Name,_, _, A),
    sum_list(A,Catomic_Number).

ion( Name , Charge ):-
    catom(Name,_, _, L),
    last(L,Last),
    getCharge(Last,Charge).

findAllPossible(Catom_List,T,0) :-
    T is 0 ,
    Catom_List = [].

findAllPossible(Catom_List,Total_Charge,Total_Catomic_Number) :-
    Total_Catomic_Number > 0,
    catomic_number(Name,Current),
    Current =< Total_Catomic_Number,
    ion(Name,Charge),    
    Rest is Total_Catomic_Number - Current,
    findAllPossible(Rest_List,Remaining_Charge,Rest),
    Total_Charge is Charge + Remaining_Charge,
    Catom_List = [Name | Rest_List].

eleminateDuplicates([_|[]]).
eleminateDuplicates([H,M|Rest]) :-
    catomic_number(H,CNH),
    catomic_number(M,CNM),
    CNH =< CNM,
    eleminateDuplicates([M|Rest]).

molecule(Catom_List, Total_Catomic_Number) :-
    findAllPossible(Catom_List,Total_Charge,Total_Catomic_Number),
    Total_Charge = 0,
    eleminateDuplicates(Catom_List).