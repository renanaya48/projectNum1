#include "Command.h"
#include <list>
#include "BoolExpression.h"
#include <map>
#include "CreateExpression.h"
#include "SymbolTable.h"
#include "ExpressionCommand.h"
#include "CommandMap.h"

#ifndef PROJECTNUM1_CONDITIONPARSER_H
#define PROJECTNUM1_CONDITIONPARSER_H


class ConditionParser : public Command {
    // Members
    list<ExpressionCommand *> expressionCommandList;
    CommandMap *commandMap;
    BoolExpression *boolExpression;
    SymbolTable *symbolTable;
    CreateExpression* createExpression;

public:
//    // Constructor empty
//    ConditionParser();
    // Constructor by CommandMap and SymbolTable

    ConditionParser(CommandMap *commandMap, SymbolTable *symbolMap, CreateExpression* create);

    // Distructor

    virtual ~ConditionParser(){};

    /**
    * The function create execute to ConditionParser by iterator
    */
    virtual int doCommand(vector<string>::iterator &script);

    /**
    * The function createCommand run over all the loop and create commands
    */
    void createCommand(vector<string>::iterator &script);

};


#endif //PROJECTNUM1_CONDITIONPARSER_H
