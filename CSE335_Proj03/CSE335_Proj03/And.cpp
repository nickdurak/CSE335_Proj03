//
//  And.cpp
//  CSE335_Proj03
//
//  Created by Nick Durak on 3/11/14.
//  Copyright (c) 2014 Nick Durak. All rights reserved.
//

#include "And.h"
#include "LogicExprVisitor.h"

void And::accept(LogicExprVisitor *v)
{
    v->visitAnd(this);
}