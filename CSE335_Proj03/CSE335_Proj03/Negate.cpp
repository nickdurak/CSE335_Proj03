//
//  Negate.cpp
//  CSE335_Proj03
//
//  Created by Nick Durak on 3/11/14.
//  Copyright (c) 2014 Nick Durak. All rights reserved.
//

#include "Negate.h"
#include "LogicExpr.h"
#include "LogicExprVisitor.h"

LogicExpr* Negate::getExpr()
{
    return m_exprPtr;
}

void Negate::accept(LogicExprVisitor* v)
{
    
}