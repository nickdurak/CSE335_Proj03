//
//  EvaluateVisitor.cpp
//  CSE335_Proj03
//
//  Created by Nick Durak on 3/13/14.
//  Copyright (c) 2014 Nick Durak. All rights reserved.
//

#include <iostream>
#include <stack>
#include "EvaluateVisitor.h"
#include "Literal.h"
#include "Negate.h"
#include "Variable.h"
#include "BoolExpr.h"
#include "And.h"
#include "Or.h"
#include "Implication.h"
#include "Equivalence.h"

using namespace std;

double EvaluateVisitor::getValue()
{
    bool result = m_myStack.top();
    m_myStack.pop();
    return result;
}

void EvaluateVisitor::visitLiteral(Literal* lit)
{
    m_myStack.push(lit->getValue());
}

void EvaluateVisitor::visitVariable(Variable* var)
{
    if (var->getValue()) {
        <#statements#>
    }
}

void EvaluateVisitor::visitNegate(Negate* neg)
{

}

void EvaluateVisitor::visitAnd(And* a)
{

}

void EvaluateVisitor::visitOr(Or* o)
{

}

void EvaluateVisitor::visitImplication(Implication* impl)
{

}

void EvaluateVisitor::visitEquivalence(Equivalence* equiv)
{

}