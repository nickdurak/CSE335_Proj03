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

bool EvaluateVisitor::getValue()
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
    if (var->getAssigned())
    {
        m_myStack.push(var->getValue());
        return;
    }
    bool assign;
    cout << "Please assign a value (0 or 1) to " << var->getName() << ":\n";
    cin >> assign;
    var->assign(assign);
    m_myStack.push(var->getValue());
}

void EvaluateVisitor::visitNegate(Negate* neg)
{
    neg->getExpr()->accept(this);
    
    bool val = m_myStack.top();
    
    m_myStack.pop();
    m_myStack.push(!val);
}

void EvaluateVisitor::visitAnd(And* a)
{
    a->getLeftExpr()->accept(this);
    a->getRightExpr()->accept(this);
    
    bool rval = m_myStack.top();
    m_myStack.pop();
    bool lval = m_myStack.top();
    m_myStack.pop();
    
    m_myStack.push(lval && rval);
}

void EvaluateVisitor::visitOr(Or* o)
{
    o->getLeftExpr()->accept(this);
    o->getRightExpr()->accept(this);
    
    bool rval = m_myStack.top();
    m_myStack.pop();
    bool lval = m_myStack.top();
    m_myStack.pop();
    
    m_myStack.push(lval || rval);
}

void EvaluateVisitor::visitImplication(Implication* impl)
{
    impl->getLeftExpr()->accept(this);
    impl->getRightExpr()->accept(this);
    
    bool rval = m_myStack.top();
    m_myStack.pop();
    bool lval = m_myStack.top();
    m_myStack.pop();
    
    m_myStack.push(!lval || rval);
}

void EvaluateVisitor::visitEquivalence(Equivalence* equiv)
{
    equiv->getLeftExpr()->accept(this);
    equiv->getRightExpr()->accept(this);
    
    bool rval = m_myStack.top();
    m_myStack.pop();
    bool lval = m_myStack.top();
    m_myStack.pop();
    
    m_myStack.push(lval == rval);
}