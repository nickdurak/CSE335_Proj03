/******************************************************
 FILE: Variable.h
 
 ABSTRACT:
 Provides declaration for Variable.
 
 AUTHOR:
 Nick Durak
 Barend Ungrodt
 
 CREATION DATE:
 11/03/2014
 
 *******************************************************/

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
    //Variable(const Variable& other);
    bool getValue() const;
    bool getAssigned() const;
    std::string getName() const;
    void assign(bool val);
    
    
    virtual void accept(LogicExprVisitor* v);
};

#endif /* defined(__CSE335_Proj03__Variable__) */
