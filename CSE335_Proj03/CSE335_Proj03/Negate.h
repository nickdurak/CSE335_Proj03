//
//  Negate.h
//  CSE335_Proj03
//
//  Created by Nick Durak on 3/11/14.
//  Copyright (c) 2014 Nick Durak. All rights reserved.
//

#ifndef __CSE335_Proj03__Negate__
#define __CSE335_Proj03__Negate__

#include <iostream>
#include "LogicExpr.h"

class LogicExprVisitor;

class Negate: public LogicExpr
{
private:
    LogicExpr* m_exprPtr;
    
public:
    Negate(LogicExpr* expr): m_exprPtr(expr) {};
    Negate(const Negate& other);
    Negate& operator= (const Negate& other);
    virtual ~Negate() {delete m_exprPtr;};
    LogicExpr* getExpr() const;
    
    virtual void accept(LogicExprVisitor* v);
};

#endif /* defined(__CSE335_Proj03__Negate__) */
