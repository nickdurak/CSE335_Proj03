//
//  LogicExpr.h
//  CSE335_Proj03
//
//  Created by Nick Durak on 3/11/14.
//  Copyright (c) 2014 Nick Durak. All rights reserved.
//

#ifndef __CSE335_Proj03__LogicExpr__
#define __CSE335_Proj03__LogicExpr__

#include <iostream>

class LogicExprVisitor;

class LogicExpr
{
public:
    virtual void accept(LogicExprVisitor*) = 0;
    virtual ~LogicExpr() = 0;
};

#endif /* defined(__CSE335_Proj03__LogicExpr__) */
