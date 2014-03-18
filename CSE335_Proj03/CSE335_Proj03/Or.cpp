//
//  Or.cpp
//  CSE335_Proj03
//
//  Created by Nick Durak on 3/11/14.
//  Copyright (c) 2014 Nick Durak. All rights reserved.
//

#include "Or.h"
#include "LogicExprVisitor.h"

/*Or::Or(Or& other)
{
    Or(other.getLeftExpr(), other.getRightExpr());
}*/

void Or::accept(LogicExprVisitor *v)
{
    v->visitOr(this);
}