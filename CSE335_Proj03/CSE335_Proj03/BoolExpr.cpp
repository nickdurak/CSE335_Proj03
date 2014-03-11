//
//  BoolExpr.cpp
//  CSE335_Proj03
//
//  Created by Nick Durak on 3/11/14.
//  Copyright (c) 2014 Nick Durak. All rights reserved.
//

#include "BoolExpr.h"
#include "LogicExpr.h"
#include "LogicExprVisitor.h"

LogicExpr* BoolExpr::getLeftExpr()
{
    return m_leftPtr;
}

LogicExpr* BoolExpr::getRightExpr()
{
    return m_rightPtr;
}

