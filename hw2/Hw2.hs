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


bindNormal (ASTNode (ASTLetDatum var) left EmptyAST) = EmptyAST
bindNormal (ASTNode (ASTLetDatum var) left right) = 
    case (getDatum right) of
        ASTSimpleDatum "plus" -> ASTNode (ASTSimpleDatum "plus") (bindNormal (ASTNode (ASTLetDatum var) left (getLeft right))) (bindNormal (ASTNode (ASTLetDatum var) left (getRight right)))
        ASTSimpleDatum "times" -> ASTNode (ASTSimpleDatum "times") (bindNormal (ASTNode (ASTLetDatum var) left (getLeft right))) (bindNormal (ASTNode (ASTLetDatum var) left (getRight right)))
        ASTSimpleDatum "cat" -> ASTNode (ASTSimpleDatum "cat") (bindNormal (ASTNode (ASTLetDatum var) left (getLeft right))) (bindNormal (ASTNode (ASTLetDatum var) left (getRight right)))
        ASTSimpleDatum "negate" -> ASTNode (ASTSimpleDatum "negate") (bindNormal (ASTNode (ASTLetDatum var) left (getLeft right))) (bindNormal (ASTNode (ASTLetDatum var) left (getRight right)))
        ASTSimpleDatum "len" -> ASTNode (ASTSimpleDatum "len") (bindNormal (ASTNode (ASTLetDatum var) left (getLeft right))) (bindNormal (ASTNode (ASTLetDatum var) left (getRight right)))
        ASTSimpleDatum "num" -> ASTNode (ASTSimpleDatum "num") (bindNormal (ASTNode (ASTLetDatum var) left (getLeft right))) (bindNormal (ASTNode (ASTLetDatum var) left (getRight right)))
        ASTSimpleDatum "str" -> ASTNode (ASTSimpleDatum "str") (bindNormal (ASTNode (ASTLetDatum var) left (getLeft right))) (bindNormal (ASTNode (ASTLetDatum var) left (getRight right)))
        ASTSimpleDatum dat ->   if(dat == var) -- dat == variable like x
                                    then left
                                else -- dat == cat || len || plus || times || negate
                                    ASTNode (ASTSimpleDatum dat) EmptyAST EmptyAST
        ASTLetDatum dat ->  if(dat == var)
                                then bindNormal right
                            else
                                ASTNode (ASTLetDatum dat) (bindNormal (ASTNode (ASTLetDatum var) left (getLeft right))) (bindNormal (ASTNode (ASTLetDatum var) left (getRight right)))
        
bindNormal (ASTNode (ASTSimpleDatum var) left right) = (ASTNode (ASTSimpleDatum var) (bindNormal left) (bindNormal right))
bindNormal EmptyAST = EmptyAST
        

bindEager (ASTNode (ASTLetDatum var) left EmptyAST) = EmptyAST
bindEager (ASTNode (ASTLetDatum var) left right) =
    let left_result = evaluate left
    in 
    case (getDatum right) of
        ASTSimpleDatum "plus" -> ASTNode (ASTSimpleDatum "plus") (bindEager (ASTNode (ASTLetDatum var) left (getLeft right) )) (bindEager (ASTNode (ASTLetDatum var) left (getRight right) ))
        ASTSimpleDatum "times" -> ASTNode (ASTSimpleDatum "times") (bindEager (ASTNode (ASTLetDatum var) left (getLeft right) )) (bindEager (ASTNode (ASTLetDatum var) left (getRight right) ))
        ASTSimpleDatum "cat" -> ASTNode (ASTSimpleDatum "cat") (bindEager (ASTNode (ASTLetDatum var) left (getLeft right) )) (bindEager (ASTNode (ASTLetDatum var) left (getRight right) ))
        ASTSimpleDatum "len" -> ASTNode (ASTSimpleDatum "len") (bindEager (ASTNode (ASTLetDatum var) left (getLeft right) )) (bindEager (ASTNode (ASTLetDatum var) left (getRight right) ))
        ASTSimpleDatum "negate" -> ASTNode (ASTSimpleDatum "negate") (bindEager (ASTNode (ASTLetDatum var) left (getLeft right) )) (bindEager (ASTNode (ASTLetDatum var) left (getRight right) ))
        ASTSimpleDatum "num" -> ASTNode (ASTSimpleDatum "num") (bindEager (ASTNode (ASTLetDatum var) left (getLeft right) )) (bindEager (ASTNode (ASTLetDatum var) left (getRight right) ))
        ASTSimpleDatum "str" -> ASTNode (ASTSimpleDatum "str") (bindEager (ASTNode (ASTLetDatum var) left (getLeft right) )) (bindEager (ASTNode (ASTLetDatum var) left (getRight right) ))     
        ASTSimpleDatum dat ->   if(dat == var) -- dat == variable like x
                                    then 
                                    if(identify left == "num")
                                        then ASTNode (ASTSimpleDatum "num") (ASTNode (ASTSimpleDatum left_result) EmptyAST EmptyAST ) EmptyAST
                                    else
                                        ASTNode (ASTSimpleDatum "str") (ASTNode (ASTSimpleDatum left_result) EmptyAST EmptyAST ) EmptyAST         
                                else -- dat == cat || len || plus || times || negate
                                    ASTNode (ASTSimpleDatum dat) EmptyAST EmptyAST
                        
        ASTLetDatum dat ->  if(dat == var)
                                then bindEager right  
                            else ASTNode (ASTLetDatum dat) (bindEager (ASTNode (ASTLetDatum var) left (getLeft right) )) (bindEager (ASTNode (ASTLetDatum var) left (getRight right) ))    
bindEager (ASTNode (ASTSimpleDatum var) left right) = ASTNode (ASTSimpleDatum var) (bindEager left) (bindEager right)
bindEager EmptyAST = EmptyAST

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
checkError (ASTNode (ASTSimpleDatum "times") left right) = elem (getElement $ getDatum $ left) ["str","cat"]  || elem (getElement $ getDatum $ right) ["str","cat"] ||  checkError left || checkError right
checkError (ASTNode (ASTSimpleDatum "plus") left right) = elem (getElement $ getDatum $ left) ["str","cat"]  || elem (getElement $ getDatum $ right) ["str","cat"] ||  checkError left || checkError right
checkError (ASTNode (ASTSimpleDatum "negate") left right) =  elem (getElement $ getDatum $ left) ["str","cat"] || checkError left
checkError (ASTNode (ASTSimpleDatum "len") left right) = elem (getElement $ getDatum $ left) ["times","plus","negate","len","num"] || checkError left
checkError (ASTNode (ASTSimpleDatum "cat") left right) = elem (getElement $ getDatum $ left) ["times","plus","negate","len","num"] || elem (getElement $ getDatum $ right) ["times","plus","negate","len","num"] || checkError left || checkError right
checkError (ASTNode (ASTSimpleDatum str) left right) = False
checkError (ASTNode (ASTLetDatum _) left right)  = checkError left || checkError right  


shouldBindMore (ASTNode (ASTSimpleDatum _) left right) = False || shouldBindMore left || shouldBindMore right
shouldBindMore (ASTNode (ASTLetDatum _) left right) = True || shouldBindMore left || shouldBindMore right
shouldBindMore EmptyAST = False

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
showError (ASTNode (ASTLetDatum _ ) left right) = showError left        

normalEvaluation all@(ASTNode datum left right) = 
    if(shouldBindMore all)
        then normalEvaluation (bindNormal all)
    else if(checkError $ bindNormal all)
        then showError $ bindNormal all
    else ASTJust (evaluate (bindNormal all),identify(bindNormal all),step (bindNormal all))
    
eagerEvaluation' all@(ASTNode (ASTSimpleDatum datum) left right) c  = 
    if(checkError $ bindEager all)
        then showError all
    else ASTJust (evaluate (bindEager all), identify (bindEager all), step all+c)

eagerEvaluation' all@(ASTNode (ASTLetDatum datum) left right) c = 
    if(checkError left)
        then showError left
    else if (shouldBindMore left)
        then eagerEvaluation' (ASTNode (ASTLetDatum datum) (bindEager left) right) (step left)
    else if (shouldBindMore all)
        then eagerEvaluation' (bindEager all) (step left)     
    else ASTJust (evaluate (bindEager all), identify (bindEager all), step all+c)

eagerEvaluation ast = eagerEvaluation' ast 0    