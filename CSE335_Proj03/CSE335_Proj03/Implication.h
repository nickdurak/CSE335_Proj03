//
//  Implication.h
//  CSE335_Proj03
//
//  Created by Nick Durak on 3/11/14.
//  Copyright (c) 2014 Nick Durak. All rights reserved.
//

#ifndef __CSE335_Proj03__Implication__
#define __CSE335_Proj03__Implication__

#include <iostream>
#include "BoolExpr.h"

class LogicExprVisitImplication;

class Implication: public BoolExpr
{
public:
    Implication(LogicExpr* left, LogicExpr* right): BoolExpr(left, right) {};
    Implication(const Implication& other);
    Implication& operator= (const Implication& other);
    virtual void accept(LogicExprVisitor* v);
};

#endif /* defined(__CSE335_Proj03__Implication__) */
