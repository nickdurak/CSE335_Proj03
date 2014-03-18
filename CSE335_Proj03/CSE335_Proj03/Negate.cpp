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

/*Negate::Negate(const Negate& other)
{
    Negate(other.getExpr());
}*/

LogicExpr* Negate::getExpr() const
{
    return m_exprPtr;
}

void Negate::accept(LogicExprVisitor* v)
{
    v->visitNegate(this);
}