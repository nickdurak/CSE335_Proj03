//
//  BoolExpr.h
//  CSE335_Proj03
//
//  Created by Nick Durak on 3/11/14.
//  Copyright (c) 2014 Nick Durak. All rights reserved.
//

#ifndef __CSE335_Proj03__BoolExpr__
#define __CSE335_Proj03__BoolExpr__

#include <iostream>
#include "LogicExpr.h"

class LogicExprVisitor;

class BoolExpr: public LogicExpr
{
private:
    LogicExpr* m_leftPtr;
    LogicExpr* m_rightPtr;
    
public:
    BoolExpr(LogicExpr* left, LogicExpr* right): m_leftPtr(left), m_rightPtr(right) {};
    BoolExpr(const BoolExpr& other);
    BoolExpr& operator= (const BoolExpr& other);
    virtual ~BoolExpr();
    
    LogicExpr* getLeftExpr() const;
    LogicExpr* getRightExpr() const;
};

#endif /* defined(__CSE335_Proj03__BoolExpr__) */
