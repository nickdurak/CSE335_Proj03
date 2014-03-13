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

using namespace std;

bool Variable::getValue()
{
    return m_value;
}

bool Variable::getAssigned()
{
    return m_assigned;
}

string Variable::getName()
{
    return m_name;
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