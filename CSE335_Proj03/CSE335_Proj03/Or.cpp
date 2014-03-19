//
//  Or.cpp
//  CSE335_Proj03
//
//  Created by Nick Durak on 3/11/14.
//  Copyright (c) 2014 Nick Durak. All rights reserved.
//

#include "Or.h"
#include "LogicExprVisitor.h"

Or::Or(const Or& other): BoolExpr(other) {}

Or & Or::operator= (const Or& other)
{
    return *this;
}

void Or::accept(LogicExprVisitor *v)
{
    v->visitOr(this);
}