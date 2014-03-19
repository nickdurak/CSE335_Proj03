//
//  Implication.cpp
//  CSE335_Proj03
//
//  Created by Nick Durak on 3/11/14.
//  Copyright (c) 2014 Nick Durak. All rights reserved.
//

#include "Implication.h"
#include "LogicExprVisitor.h"

Implication::Implication(const Implication& other): BoolExpr(other) {}

Implication & Implication::operator= (const Implication& other)
{
    return *this;
}


void Implication::accept(LogicExprVisitor *v)
{
    v->visitImplication(this);
}