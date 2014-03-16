//
//  Variable.h
//  CSE335_Proj03
//
//  Created by Nick Durak on 3/11/14.
//  Copyright (c) 2014 Nick Durak. All rights reserved.
//

#ifndef __CSE335_Proj03__Variable__
#define __CSE335_Proj03__Variable__

#include <iostream>
#include <string>
#include "LogicExpr.h"

class LogicExprVisitor;

class Variable: public LogicExpr
{
private:
    bool m_value;
    bool m_assigned;
    std::string m_name;
    
public:
    Variable(std::string name = "NOT SET!"): m_assigned(false), m_name(name) {};
    bool getValue();
    bool getAssigned();
    std::string getName();
    void assign(bool val);
    
    
    virtual void accept(LogicExprVisitor* v);
};

#endif /* defined(__CSE335_Proj03__Variable__) */
