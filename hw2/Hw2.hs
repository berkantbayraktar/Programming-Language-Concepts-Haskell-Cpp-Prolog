module Hw2 where

data ASTResult = ASTError String | ASTJust (String, String, Int) deriving (Show, Read)
data ASTDatum = ASTSimpleDatum String | ASTLetDatum String deriving (Show, Read)
data AST = EmptyAST | ASTNode ASTDatum AST AST deriving (Show, Read)

isNumber :: String -> Bool
eagerEvaluation :: AST -> ASTResult
normalEvaluation :: AST -> ASTResult
-- DO NOT MODIFY OR DELETE THE LINES ABOVE -- 
-- IMPLEMENT isNumber, eagerEvaluation and normalEvaluation FUNCTIONS ACCORDING TO GIVEN SIGNATURES -- 
evaluate :: AST -> String

isNumberHelper [] = True
isNumberHelper (x:xs) = (x >= '0' && x <= '9') && (isNumberHelper xs)
isNumber [] = False
isNumber (x:xs) = (x >= '0' && x <= '9' || x== '-') && (isNumberHelper xs)

getDatum (ASTNode datum _ _ ) = datum
getLeft (ASTNode _ left _ ) = left
getRight (ASTNode _ _ right) = right
getElement (ASTSimpleDatum ele) = ele
getElement (ASTLetDatum ele) = ele


bindNormal (ASTNode (ASTLetDatum var) left right) = 
    case (getDatum right) of
        ASTSimpleDatum dat ->   if(dat == var) -- dat == variable like x
                                    then left
                                else if (dat =="num" || dat == "str")
                                    then right
                                else -- dat == cat || len || plus || times || negate
                                    if ( getElement (getDatum(getLeft right)) == var && getElement (getDatum(getRight right)) == var)
                                        then ASTNode (ASTSimpleDatum dat) left left
                                    else if (getElement (getDatum(getLeft right)) == var) 
                                        then ASTNode (ASTSimpleDatum dat) left (bindNormal (ASTNode (ASTLetDatum var) left (getRight right)))
                                    else if (getElement (getDatum(getRight right)) == var)
                                        then ASTNode (ASTSimpleDatum dat) (bindNormal (ASTNode (ASTLetDatum var) left (getLeft right))) left
                                    else
                                        ASTNode (ASTSimpleDatum dat) (bindNormal (ASTNode (ASTLetDatum var) left (getLeft right))) (bindNormal (ASTNode (ASTLetDatum var) left (getRight right)))
        ASTLetDatum dat -> bindNormal right
        
bindNormal (ASTNode (ASTSimpleDatum var) left right) = (ASTNode (ASTSimpleDatum var) left right)
        

bindEager (ASTNode (ASTLetDatum var) left right) =
    let left_result = evaluate left
    in 
    case (getDatum right) of
        ASTSimpleDatum dat ->   if(dat == var) -- dat == variable like x
                                    then 
                                    if(identify left == "num")
                                        then ASTNode (ASTSimpleDatum "num") (ASTNode (ASTSimpleDatum left_result) EmptyAST EmptyAST ) EmptyAST
                                    else
                                        ASTNode (ASTSimpleDatum "str") (ASTNode (ASTSimpleDatum left_result) EmptyAST EmptyAST ) EmptyAST    
                                else if(dat == "num" || dat == "str")
                                    then right        
                                else -- dat == cat || len || plus || times || negate
                                    if((getElement $ getDatum $ getLeft $ right) == var &&  (getElement $ getDatum $ getRight $ right) == var) 
                                        then 
                                        if(identify left == "num")
                                            then ASTNode (ASTSimpleDatum dat)  (ASTNode (ASTSimpleDatum "num") (ASTNode (ASTSimpleDatum left_result) EmptyAST EmptyAST ) EmptyAST ) (ASTNode (ASTSimpleDatum "num") (ASTNode (ASTSimpleDatum left_result) EmptyAST EmptyAST ) EmptyAST )         
                                        else 
                                            ASTNode (ASTSimpleDatum dat) (ASTNode (ASTSimpleDatum "str") (ASTNode (ASTSimpleDatum left_result) EmptyAST EmptyAST ) EmptyAST) (ASTNode (ASTSimpleDatum "str") (ASTNode (ASTSimpleDatum left_result) EmptyAST EmptyAST ) EmptyAST)
                                    else if ((getElement $ getDatum $ getLeft $ right) == var)
                                        then
                                        if(identify left == "num")
                                            then ASTNode (ASTSimpleDatum dat) (ASTNode (ASTSimpleDatum "num") (ASTNode (ASTSimpleDatum left_result) EmptyAST EmptyAST ) EmptyAST) (bindEager (ASTNode (ASTLetDatum var) left (getRight right) )) 
                                        else
                                            ASTNode (ASTSimpleDatum dat) (ASTNode (ASTSimpleDatum "str") (ASTNode (ASTSimpleDatum left_result) EmptyAST EmptyAST ) EmptyAST) (bindEager (ASTNode (ASTLetDatum var) left (getRight right) ))
                                    else if ((getElement $ getDatum $ getRight $ right) == var)
                                        then
                                        if(identify left == "num")
                                            then ASTNode (ASTSimpleDatum dat) (bindEager (ASTNode (ASTLetDatum var) left (getLeft right) )) (ASTNode (ASTSimpleDatum "num") (ASTNode (ASTSimpleDatum left_result) EmptyAST EmptyAST ) EmptyAST)
                                        else
                                            ASTNode (ASTSimpleDatum dat) (bindEager (ASTNode (ASTLetDatum var) left (getLeft right) )) (ASTNode (ASTSimpleDatum "str") (ASTNode (ASTSimpleDatum left_result) EmptyAST EmptyAST ) EmptyAST)       
                                    else    
                                        ASTNode (ASTSimpleDatum dat) (bindEager (ASTNode (ASTLetDatum var) left (getLeft right) )) (bindEager (ASTNode (ASTLetDatum var) left (getRight right) ))
                                    

        ASTLetDatum dat -> bindEager right    
bindEager (ASTNode (ASTSimpleDatum var) left right) = (ASTNode (ASTSimpleDatum var) left right)

evaluate (ASTNode (ASTSimpleDatum "cat") left right) = evaluate left ++ evaluate right
evaluate (ASTNode (ASTSimpleDatum "str") left right) = evaluate left
evaluate (ASTNode (ASTSimpleDatum "len") left right) = show (length (evaluate left ))
evaluate (ASTNode (ASTSimpleDatum "plus") left right) = show ((read (evaluate left) :: Integer) + (read (evaluate right) :: Integer ))
evaluate (ASTNode (ASTSimpleDatum "times") left right) = show ((read (evaluate left) :: Integer) * (read (evaluate right) :: Integer ))
evaluate (ASTNode (ASTSimpleDatum "negate") left right) = show (-(read (evaluate left) :: Integer))
evaluate (ASTNode (ASTSimpleDatum "num") left right) = evaluate left
evaluate (ASTNode (ASTSimpleDatum str) left right) = str

step EmptyAST = 0
step (ASTNode (ASTLetDatum var) left right) =
    0 + step left + step right
step (ASTNode (ASTSimpleDatum var) left right) = 
    if(var == "cat" || var == "len" || var == "times" || var == "negate"  || var == "plus")
        then (1 + step left + step right)
    else -- var==str || var == num
        0

identify (ASTNode (ASTSimpleDatum var) _ _) =
    if(var == "len" || var == "times" || var == "negate"  || var == "plus" || var == "num")
        then "num"
    else if(var == "cat" || var == "str")
        then "str"
    else
        "error"                 
        
checkError (ASTNode (ASTSimpleDatum "num") left right) = not ( elem (getElement $ getDatum $ left) ["times","plus","negate","len"]  ||  ( isNumber $ getElement $ getDatum $ left)) || checkError left
checkError (ASTNode (ASTSimpleDatum "str") left right) = False
checkError (ASTNode (ASTSimpleDatum "times") left right) = not (elem (getElement $ getDatum $ left) ["num","times","plus","negate","len"]  && elem (getElement $ getDatum $ right) ["num","times","plus","negate","len"] ) ||  checkError left || checkError right
checkError (ASTNode (ASTSimpleDatum "plus") left right) = not (elem (getElement $ getDatum $ left) ["num","times","plus","negate","len"]  && elem (getElement $ getDatum $ right) ["num","times","plus","negate","len"]) ||  checkError left || checkError right
checkError (ASTNode (ASTSimpleDatum "negate") left right) =  not (elem (getElement $ getDatum $ left) ["num","times","plus","negate","len"]) || checkError left
checkError (ASTNode (ASTSimpleDatum "len") left right) = not ( elem (getElement $ getDatum $ left) ["str","cat"]) || checkError left
checkError (ASTNode (ASTSimpleDatum "cat") left right) = not ( elem (getElement $ getDatum $ left) ["str","cat"] && elem (getElement $ getDatum $ right) ["str","cat"]) || checkError left || checkError right
checkError (ASTNode (ASTSimpleDatum str) left right) = False
    
showError (ASTNode (ASTSimpleDatum "num") left right) = 
    if (isNumber $ getElement $ getDatum $ left)
        then ASTError ("error")
    else
        ASTError ("the value '" ++ (getElement $ getDatum $ left) ++ "' is not a number!") 

showError (ASTNode (ASTSimpleDatum "plus") left right) = 
    if (checkError left)
        then showError left
    else if(checkError right)
        then showError right    
    else
        ASTError ("plus operation is not defined between " ++ (getElement $ getDatum $ left) ++ " and " ++ (getElement $ getDatum $ right) ++ "!") 

showError (ASTNode (ASTSimpleDatum "times") left right) = 
    if (checkError left)
        then showError left
    else if(checkError right)
        then showError right    
    else
        ASTError ("times operation is not defined between " ++ (getElement $ getDatum $ left) ++ " and " ++ (getElement $ getDatum $ right) ++ "!")

showError (ASTNode (ASTSimpleDatum "cat") left right) = 
    if (checkError left)
        then showError left
    else if(checkError right)
        then showError right    
    else
        ASTError ("cat operation is not defined between " ++ (getElement $ getDatum $ left) ++ " and " ++ (getElement $ getDatum $ right) ++ "!")

showError (ASTNode (ASTSimpleDatum "negate") left right) = 
    if (checkError left)
        then showError left   
    else
        ASTError ("negate operation is not defined on " ++ (getElement $ getDatum $ left) ++ "!")

showError (ASTNode (ASTSimpleDatum "len") left right) = 
    if (checkError left)
        then showError left   
    else
        ASTError ("len operation is not defined on " ++ (getElement $ getDatum $ left) ++ "!")                  


showError (ASTNode (ASTSimpleDatum "str") left right) = ASTError "Something wrong"
showError (ASTNode (ASTSimpleDatum others) left right) = ASTError ("Something wrong")
        

normalEvaluation all@(ASTNode datum left right) = 
    if(checkError $ bindNormal all)
        then showError $ bindNormal all
    else ASTJust (evaluate (bindNormal all),identify(bindNormal all),step (bindNormal all))
    
eagerEvaluation all@(ASTNode datum left right) = 
    if(checkError $ bindEager all)
        then showError all
    else ASTJust (evaluate (bindEager all), identify (bindEager all), step all)