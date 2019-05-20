:- module(hw5,[catomic_number/2, ion/2, molecule/2]).
:- [catoms].

catomic_number(Name, Catomic_Number) :-
    catom(Name,_, _, A),
    sum_list(A,Catomic_Number).

ion( Name , Charge ):-
    catom(Name,_, _, L),
    last(L,Last),
    (Last =< 4 -> Charge is Last ; Charge is (Last - 8)).

findAllPossible(Catom_List,T,0,_) :- 
    T is 0 ,
    Catom_List = [].

findAllPossible(Catom_List,Total_Charge,Total_Catomic_Number,LL) :-
    Total_Catomic_Number > 0,
    catomic_number(Name,Current),
    Current >=  LL,
    Current =< Total_Catomic_Number,
    ion(Name,Charge),    
    Rest is Total_Catomic_Number - Current,
    ML is Current,
    findAllPossible(Rest_List,Remaining_Charge,Rest,ML),
    Total_Charge is Charge + Remaining_Charge,
    Catom_List = [Name | Rest_List].

molecule(Catom_List, Total_Catomic_Number) :-
    findAllPossible(Catom_List,Total_Charge,Total_Catomic_Number,0),
    Total_Charge = 0.