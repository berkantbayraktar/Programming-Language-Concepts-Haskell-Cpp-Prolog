module Hw1 where

type Mapping = [(String, String, String)]
data AST = EmptyAST | ASTNode String AST AST deriving (Show, Read)
    
writeExpression :: (AST, Mapping) -> String
evaluateAST :: (AST, Mapping) -> (AST, String)
-- DO NOT MODIFY OR DELETE THE LINES ABOVE -- 
-- IMPLEMENT writeExpression and evaluateAST FUNCTION ACCORDING TO GIVEN SIGNATURES -- 



getFirst :: (String, String, String) -> String
getFirst (str,_,_) = str
getSecond :: (String, String, String) -> String
getSecond (_,str,_) = str
getThird :: (String, String, String) -> String
getThird (_,_,str) = str
myPrint :: [(String, String, String)] -> String
myPrint (x:xs) = if(null xs)
                    then do
                        case getSecond x of
                            "num" -> getFirst x ++ "=" ++ getThird x ++ " in "
                            "str" -> getFirst x ++ "=\"" ++ getThird x ++ "\"" ++" in " 
                    else do
                        case getSecond x of
                            "num" -> getFirst x ++ "=" ++ getThird x ++ ";"  ++ myPrint xs
                            "str" -> getFirst x ++ "=\"" ++ getThird x ++ "\";" ++ myPrint xs


writeExpression (EmptyAST,null) = ""
writeExpression (ASTNode str leftAST rightAST,all@(x:xs)) = if(null xs) 
                                                                then do
                                                                    case getSecond x of
                                                                        "num" -> "let " ++ getFirst x ++ "=" ++ getThird x ++ " in " ++ writeExpression(ASTNode str leftAST rightAST,[])
                                                                        "str" -> "let " ++ getFirst x ++ "=\"" ++ getThird x ++ "\"" ++ " in " ++ writeExpression(ASTNode str leftAST rightAST,[])                                                                  
                                                                else do
                                                                    "let " ++ (myPrint all) ++ writeExpression(ASTNode str leftAST rightAST,[])


writeExpression (ASTNode str leftAST rightAST,[]) =  case str of
                                                            "num" -> writeExpression (leftAST,[]) ++ writeExpression(rightAST,[])
                                                            "str" -> "\"" ++ writeExpression(leftAST,[]) ++ writeExpression(rightAST,[]) ++ "\""
                                                            "len" -> "(" ++ "length " ++ writeExpression(leftAST,[]) ++ writeExpression(rightAST,[]) ++ ")"
                                                            "plus" -> "(" ++ writeExpression(leftAST,[]) ++ "+" ++ writeExpression(rightAST,[]) ++ ")"
                                                            "times" -> "(" ++ writeExpression(leftAST,[]) ++ "*" ++ writeExpression(rightAST,[]) ++ ")"
                                                            "negate" ->"(" ++ "-" ++ writeExpression(leftAST,[]) ++ writeExpression(rightAST,[]) ++ ")"
                                                            "cat" -> "(" ++ writeExpression(leftAST,[]) ++ "++" ++ writeExpression(rightAST,[]) ++ ")"
                                                            _ ->  writeExpression (leftAST,[]) ++ str  ++ writeExpression(rightAST,[])

evaluateAST all@(ASTNode "times" leftAST rightAST,[]) =     let (_,op1) =  evaluateAST(leftAST,[])
                                                                (_,op2) =  evaluateAST(rightAST,[])
                                                                result = (read op1 :: Integer) * (read op2 :: Integer)
                                                            in  (fst all,show result )

evaluateAST all@(ASTNode "plus" leftAST rightAST,[])  =     let (_,op1) =  evaluateAST(leftAST,[])
                                                                (_,op2) =  evaluateAST(rightAST,[])
                                                                result = (read op1 :: Integer) + (read op2 :: Integer)
                                                            in  (fst all,show result )

evaluateAST all@(ASTNode "cat" leftAST rightAST,[])   =     let (_,op1) =  evaluateAST(leftAST,[])
                                                                (_,op2) =  evaluateAST(rightAST,[])
                                                                result = op1 ++ op2
                                                            in (fst all, result)

evaluateAST all@(ASTNode "len" leftAST rightAST,[])   =     let (_,op1) =  evaluateAST(leftAST,[])
                                                                result = length op1                                                              
                                                            in (fst all, show result)

evaluateAST all@(ASTNode "negate" leftAST rightAST,[])=     let (_,op1) =  evaluateAST(leftAST,[])
                                                                result = -(read op1 :: Integer)                                                             
                                                            in (fst all, show result)


evaluateAST all@(ASTNode "num" leftAST rightAST,[]) =   let (_,num )= evaluateAST(leftAST,[])
                                                        in  (fst all, num)

evaluateAST all@(ASTNode "str" leftAST rightAST,[]) =   let (_,str )= evaluateAST(leftAST,[])
                                                        in  (fst all, str)


evaluateAST all@(ASTNode str leftAST rightAST, []) = (fst all , str)



evaluateAST (EmptyAST,_) = (EmptyAST,[])
evaluateAST (ASTNode str leftAST rightAST,(x:xs)) = if(null xs) 
                                                        then do 
                                                            if (str == getFirst x)
                                                                then do
                                                                    case getSecond x of
                                                                        "num" -> evaluateAST(ASTNode "num" (ASTNode (getThird x) leftAST rightAST) EmptyAST,[])   
                                                                        "str" -> evaluateAST(ASTNode "str" (ASTNode (getThird x) leftAST rightAST) EmptyAST,[])
                                                                else do
                                                                    evaluateAST(ASTNode str (fst (evaluateAST(leftAST,(x:xs)))) (fst (evaluateAST(rightAST,(x:xs))) ),[])
                                                                                                                                                                                                  
                                                        else do
                                                            if (str == getFirst x)
                                                                then do
                                                                    case getSecond x of
                                                                        "num" -> (ASTNode "num" (ASTNode (getThird x) leftAST rightAST) EmptyAST,[])   
                                                                        "str" -> (ASTNode "str" (ASTNode (getThird x) leftAST rightAST) EmptyAST,[])
                                                                else do
                                                                    evaluateAST(ASTNode str (fst (evaluateAST(leftAST,(x:xs)))) (fst (evaluateAST(rightAST,(x:xs))) ),xs)