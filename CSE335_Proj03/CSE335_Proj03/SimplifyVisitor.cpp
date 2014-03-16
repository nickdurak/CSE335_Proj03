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


/*
 if(string_name = "A & false") string_name = "false";
 if(string_name = "false & A") string_name = "false";
 if(string_name = "A & true") string_name = "A";
 if(string_name = "true & A") string_name = "A";
 if(string_name = "A | false") string_name = "A";
 if(string_name = "false | A") string_name = "A";
 if(string_name = "A | true") string_name = "true";
 if(string_name = "true | A") string_name = "true";
 if(string_name = "A > false") string_name = "~A";
 if(string_name = "false > A") string_name = "true";
 if(string_name = "A > true") string_name = "true";
 if(string_name = "true > A") string_name = "A";
 if(string_name = "A = false") string_name = "~A";
 if(string_name = "false = A") string_name = "~A";
 if(string_name = "A = true") string_name = "A";
 if(string_name = "true = A") string_name = "A";
 */
bool SimplifyVisitor::getValue()
{
    bool result = m_myStack.top();
    m_myStack.pop();
    return result;
}

void SimplifyVisitor::visitLiteral(Literal* lit)
{
    m_myStack.push(lit->getValue());
}

void SimplifyVisitor::visitVariable(Variable* var)
{
    
}

void SimplifyVisitor::visitNegate(Negate* neg)
{
    
}

void SimplifyVisitor::visitAnd(And* a)
{
    
}

void SimplifyVisitor::visitOr(Or* o)
{
    
}

void SimplifyVisitor::visitImplication(Implication* impl)
{
    
}

void SimplifyVisitor::visitEquivalence(Equivalence* equiv)
{
    
}