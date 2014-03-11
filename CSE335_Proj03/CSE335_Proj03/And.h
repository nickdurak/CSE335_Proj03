//
//  And.h
//  CSE335_Proj03
//
//  Created by Nick Durak on 3/11/14.
//  Copyright (c) 2014 Nick Durak. All rights reserved.
//

#ifndef __CSE335_Proj03__And__
#define __CSE335_Proj03__And__

#include <iostream>
#include "BoolExpr.h"

class LogicExprVisitor;

class And:BoolExpr
{
public:
    And(LogicExpr* left, LogicExpr* right): BoolExpr(left, right) {};

    virtual void accept(LogicExprVisitor* v);
};

#endif /* defined(__CSE335_Proj03__And__) */
