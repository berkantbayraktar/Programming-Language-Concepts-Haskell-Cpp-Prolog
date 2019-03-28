module Hw2 where

data ASTResult = ASTError String | ASTJust (String, String, Int) deriving (Show, Read)
data ASTDatum = ASTSimpleDatum String | ASTLetDatum String deriving (Show, Read)
data AST = EmptyAST | ASTNode ASTDatum AST AST deriving (Show, Read)

isNumber :: String -> Bool
--eagerEvaluation :: AST -> ASTResult
--normalEvaluation :: AST -> ASTResult
-- DO NOT MODIFY OR DELETE THE LINES ABOVE -- 
-- IMPLEMENT isNumber, eagerEvaluation and normalEvaluation FUNCTIONS ACCORDING TO GIVEN SIGNATURES -- 
evaluate :: AST -> String

isNumber [] = True
isNumber (x:xs) = (x >= '0' && x <= '9' || x== '-') && (isNumber xs)

getDatum (ASTNode datum _ _ ) = datum
getLeft (ASTNode _ left _ ) = left
getRight (ASTNode _ _ right) = right


bindNormal (ASTNode (ASTLetDatum var) left right) = 
    case (getDatum right) of
        ASTSimpleDatum dat ->  ASTNode (ASTSimpleDatum dat) left left
        ASTLetDatum dat -> bindNormal right
        
bindNormal (ASTNode (ASTSimpleDatum var) left right) = (ASTNode (ASTSimpleDatum var) left right)
        

evaluate (ASTNode (ASTSimpleDatum "cat") left right) = evaluate left ++ evaluate right
evaluate (ASTNode (ASTSimpleDatum "str") left right) = evaluate left
evaluate (ASTNode (ASTSimpleDatum "len") left right) = show (length (evaluate left ))
evaluate (ASTNode (ASTSimpleDatum "plus") left right) = show ((read (evaluate left) :: Integer) + (read (evaluate right) :: Integer ))
evaluate (ASTNode (ASTSimpleDatum "times") left right) = show ((read (evaluate left) :: Integer) * (read (evaluate right) :: Integer ))
evaluate (ASTNode (ASTSimpleDatum "negate") left right) = show (-(read (evaluate left) :: Integer))
evaluate (ASTNode (ASTSimpleDatum "num") left right) = evaluate left
evaluate (ASTNode (ASTSimpleDatum str) left right) = str



normalEvaluation all@(ASTNode datum left right) = evaluate (bindNormal all)



--eagerEvaluation (ASTNode datum left right) =


--eagerEvaluation (ASTNode (ASTLetDatum "x") (ASTNode (ASTSimpleDatum "plus") (ASTNode (ASTSimpleDatum "num") (ASTNode (ASTSimpleDatum "3") EmptyAST EmptyAST) EmptyAST) (ASTNode (ASTSimpleDatum "num") (ASTNode (ASTSimpleDatum "4") EmptyAST EmptyAST) EmptyAST)) (ASTNode (ASTSimpleDatum "plus") (ASTNode (ASTSimpleDatum "x") EmptyAST EmptyAST) (ASTNode (ASTSimpleDatum "x") EmptyAST EmptyAST)))
--eagerEvaluation (ASTNode (ASTLetDatum "x") ((ASTNode (ASTSimpleDatum "negate") (ASTNode (ASTSimpleDatum "times") (ASTNode (ASTSimpleDatum "plus") (ASTNode (ASTSimpleDatum "num") (ASTNode (ASTSimpleDatum "1") EmptyAST EmptyAST) EmptyAST) (ASTNode (ASTSimpleDatum "num") (ASTNode (ASTSimpleDatum "2") EmptyAST EmptyAST) EmptyAST)) (ASTNode (ASTSimpleDatum "len") (ASTNode (ASTSimpleDatum "cat") (ASTNode (ASTSimpleDatum "str") (ASTNode (ASTSimpleDatum "CE") EmptyAST EmptyAST) EmptyAST) (ASTNode (ASTSimpleDatum "str") (ASTNode (ASTSimpleDatum "NG") EmptyAST EmptyAST) EmptyAST)) EmptyAST)) EmptyAST)) (ASTNode (ASTSimpleDatum "times") (ASTNode (ASTSimpleDatum "x") EmptyAST EmptyAST) (ASTNode (ASTSimpleDatum "plus") (ASTNode (ASTSimpleDatum "x") EmptyAST EmptyAST) (ASTNode (ASTSimpleDatum "x") EmptyAST EmptyAST))))
--(ASTNode (ASTLetDatum "x") (ASTNode (ASTSimpleDatum "plus") (ASTNode (ASTSimpleDatum "num") (ASTNode (ASTSimpleDatum "2") EmptyAST EmptyAST) EmptyAST) (ASTNode (ASTSimpleDatum "num") (ASTNode (ASTSimpleDatum "3") EmptyAST EmptyAST) EmptyAST)) (ASTNode (ASTLetDatum "x") (ASTNode (ASTSimpleDatum "num") (ASTNode (ASTSimpleDatum "4") EmptyAST EmptyAST) EmptyAST) (ASTNode (ASTSimpleDatum "plus") (ASTNode (ASTSimpleDatum "x") EmptyAST EmptyAST) (ASTNode (ASTSimpleDatum "x") EmptyAST EmptyAST))))