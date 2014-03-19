/******************************************************
  FILE: Literal.cpp

  ABSTRACT:
  Provides implementation of the Literal.
 
  AUTHOR:
  Nick Durak
  Barend Ungrodt
 
  CREATION DATE:
  11/03/2014
 
 *******************************************************/

#include "Literal.h"
#include "LogicExpr.h"
#include "LogicExprVisitor.h"

Literal::Literal(const Literal& other)
{
    Literal(other.getValue());
}

bool Literal::getValue() const
{
    return m_value;
}
    
void Literal::accept(LogicExprVisitor* v)
{
    v->visitLiteral(this);
}