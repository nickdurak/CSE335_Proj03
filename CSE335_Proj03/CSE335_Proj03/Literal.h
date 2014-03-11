//
//  Literal.h
//  CSE335_Proj03
//
//  Created by Nick Durak on 3/11/14.
//  Copyright (c) 2014 Nick Durak. All rights reserved.
//

#ifndef __CSE335_Proj03__Literal__
#define __CSE335_Proj03__Literal__

#include <iostream>
#include "LogicExpr.h"

class LogicExprVisitor;

class Literal: public LogicExpr
{
private:
    bool m_value;
    
public:
    Literal(bool val = true): m_value(val) {};
    bool getValue();
    
    virtual void accept(LogicExprVisitor* v);
};

#endif /* defined(__CSE335_Proj03__Literal__) */
