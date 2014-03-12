//
//  SimplifyVisitor.cpp
//  CSE335_Proj03
//
//  Created by Barend Ungrodt on 3/11/14.
//  Copyright (c) 2014 Nick Durak. All rights reserved.
//

#include <iostream>
#include <stack>
#include "SimplifyVisitor.h"
#include "Literal.h"
#include "Negate.h"
#include "Variable.h"
#include "BoolExpr.h"
#include "And.h"
#include "Or.h"
#include "Implication.h"
#include "Equivalence.h"


void LogicExprVisitor::visitLiteral(Literal*)
{
    
}

void LogicExprVisitor::visitVariable(Variable*)
{
    
}

void LogicExprVisitor::visitNegate(Negate*)
{
    
}

void LogicExprVisitor::visitAnd(And*)
{
    
}

void LogicExprVisitor::visitOr(Or*)
{
    
}

void LogicExprVisitor::visitImplication(Implication*)
{
    
}

void LogicExprVisitor::visitEquivalence(Equivalence*)
{
    
}