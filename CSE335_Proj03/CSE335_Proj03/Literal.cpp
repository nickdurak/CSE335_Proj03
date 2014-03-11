//
//  Literal.cpp
//  CSE335_Proj03
//
//  Created by Nick Durak on 3/11/14.
//  Copyright (c) 2014 Nick Durak. All rights reserved.
//

#include "Literal.h"
#include "LogicExpr.h"
#include "LogicExprVisitor.h"

bool Literal::getValue()
{
    return m_value;
}
    
void Literal::accept(LogicExprVisitor* v)
{
    
}