//
//  PrintVisitor.cpp
//  CSE335_Proj03
//
//  Created by Barend Ungrodt on 3/11/14.
//  Copyright (c) 2014 Nick Durak. All rights reserved.
//


#include <iostream>
#include <stack>
#include "PrintVisitor.h"
#include "Literal.h"
#include "Negate.h"
#include "Variable.h"
#include "BoolExpr.h"
#include "And.h"
#include "Or.h"
#include "Implication.h"
#include "Equivalence.h"

using namespace std;

void LogicExprVisitor::visitLiteral(Literal* lit)
{
    if(lit->getValue() >= 0) cout << " " << lit->getValue() << " ";
    else cout << "(" << lit->getValue() << ")";
}

void LogicExprVisitor::visitVariable(Variable* var)
{
    if(var->getValue() >= 0) cout << " " << var->getValue() << " ";
    else cout << "(" << var->getValue() << ")";
}

void LogicExprVisitor::visitNegate(Negate* neg)
{
    cout << "(~";
    neg->getExpr()->accept(this);
    cout << ")";
}

void LogicExprVisitor::visitAnd(And* a)
{
    cout << "(";
    a->getLeftExpr()->accept(this);
    
}

void LogicExprVisitor::visitOr(Or* o)
{
    
}

void LogicExprVisitor::visitImplication(Implication* impl)
{
    
}

void LogicExprVisitor::visitEquivalence(Equivalence* equiv)
{
    
}