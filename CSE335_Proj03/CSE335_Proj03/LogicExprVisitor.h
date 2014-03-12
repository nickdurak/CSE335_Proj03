//
//  LogicExprVisitor.h
//  CSE335_Proj03
//
//  Created by Barend Ungrodt on 3/11/14.
//  Copyright (c) 2014 Nick Durak. All rights reserved.
//

#ifndef __CSE335_Proj03__LogicExprVisitor__
#define __CSE335_Proj03__LogicExprVisitor__

#include <iostream>

class Literal;
class Variable;
class Negation;
class And;
class Or;
class Implication;
class Equivalence;

class LogicExprVisitor
{
public:
    virtual void visitLiteral(Literal*) = 0;
    virtual void visitVariable(Variable*) = 0;
    virtual void visitNegation(Negation*) = 0;
    virtual void visitAnd(And*) = 0;
    virtual void visitOr(Or*) = 0;
    virtual void visitImplication(Implication*) = 0;
    virtual void visitEquivalence(Equivalence*) = 0;
};

#endif /* defined(__CSE335_Proj03__LogicExprVisitor__) */
