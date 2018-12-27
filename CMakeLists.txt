cmake_minimum_required(VERSION 3.12)
project(projectNum1)

set(CMAKE_CXX_FLAGS "-std=c++14 -pthread")
#set(CMAKE_CXX_STANDARD 14)

add_executable(projectNum1 main.cpp Command.h Mul.cpp Mul.h Minus.cpp Minus.h Plus.cpp Plus.h Div.cpp Div.h Expression.h Num.cpp Num.h CreateCommand.cpp CreateCommand.h BinaryExpression.h OpenServerCommand.cpp OpenServerCommand.h ConnectCommand.cpp ConnectCommand.h CreateExpression.cpp CreateExpression.h LoopCommand.cpp LoopCommand.h ExpressionCommand.cpp ExpressionCommand.h Var.cpp Var.h ConditionParser.cpp ConditionParser.h IfCommand.cpp IfCommand.h VarCommand.cpp VarCommand.h SymbolTable.cpp SymbolTable.h PrintCommand.cpp PrintCommand.h SleepCommand.cpp SleepCommand.h BindPathMap.cpp BindPathMap.h FlightValueMap.cpp FlightValueMap.h CheckForServerConnection.cpp CheckForServerConnection.h ValueControlForFlight.cpp ValueControlForFlight.h SetControlCommand.cpp SetControlCommand.h Neg.cpp Neg.h BoolExpression.cpp BoolExpression.h CommandMap.cpp CommandMap.h CheckEndScript.cpp CheckEndScript.h)