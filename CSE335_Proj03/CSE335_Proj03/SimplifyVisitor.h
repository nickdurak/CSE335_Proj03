//
//  SimplifyVisitor.h
//  CSE335_Proj03
//
//  Created by Barend Ungrodt on 3/11/14.
//  Copyright (c) 2014 Nick Durak. All rights reserved.
//

#ifndef __CSE335_Proj03__SimplifyVisitor__
#define __CSE335_Proj03__SimplifyVisitor__

#include <iostream>
#include <stack>
#include "LogicExprVisitor.h"
#include "PrintVisitor.h"
#include "Literal.h"
#include "Negate.h"
#include "Variable.h"
#include "And.h"
#include "Or.h"
#include "Implication.h"
#include "Equivalence.h"

class SimplifyVisitor: public LogicExprVisitor
{
private:
    std::stack<std::string> m_myStack;
public:
    std::string getValue();
    bool stringToBool(std::string const& s);
    std::string boolToString(bool const& b);
    virtual void visitLiteral(Literal* lit);
    virtual void visitNegate(Negate* neg);
    virtual void visitVariable(Variable* var);
    virtual void visitAnd(And* a);
    virtual void visitOr(Or* o);
    virtual void visitImplication(Implication* impl);
    virtual void visitEquivalence(Equivalence* equiv);
};

#endif /* defined(__CSE335_Proj03__SimplifyVisitor__) */
