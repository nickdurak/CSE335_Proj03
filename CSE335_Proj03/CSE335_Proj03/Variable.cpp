//
//  Variable.cpp
//  CSE335_Proj03
//
//  Created by Nick Durak on 3/11/14.
//  Copyright (c) 2014 Nick Durak. All rights reserved.
//

#include "Variable.h"
#include "LogicExpr.h"
#include "LogicExprVisitor.h"

bool Variable::getValue()
{
    return m_value;
}

void Variable::assign(bool val)
{
    m_value = val;
    m_assigned = true;
}

void Variable::accept(LogicExprVisitor* v)
{
    v->visitVariable(this);
}