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

void PrintVisitor::visitLiteral(Literal* lit)
{
    cout << " " << lit->getValue() << " ";
}

void PrintVisitor::visitVariable(Variable* var)
{
    cout << " " << var->getValue() << " ";
}

void PrintVisitor::visitNegate(Negate* neg)
{
    cout << "(~";
    neg->getExpr()->accept(this);
    cout << ")";
}

void PrintVisitor::visitAnd(And* a)
{
    cout << "(";
    a->getLeftExpr()->accept(this);
    cout << "&"; 
    a->getRightExpr()->accept(this);
    cout << ")";
}

void PrintVisitor::visitOr(Or* o)
{
    cout << "(";
    o->getLeftExpr()->accept(this);
    cout << "|";
    o->getRightExpr()->accept(this);
    cout << ")";
}

void PrintVisitor::visitImplication(Implication* impl)
{
    cout << "(";
    impl->getLeftExpr()->accept(this);
    cout << ">";
    impl->getRightExpr()->accept(this);
    cout << ")";
}

void PrintVisitor::visitEquivalence(Equivalence* equiv)
{
    cout << "(";
    equiv->getLeftExpr()->accept(this);
    cout << "=";
    equiv->getRightExpr()->accept(this);
    cout << ")";
}