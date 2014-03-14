//
//  EvaluateVisitor.h
//  CSE335_Proj03
//
//  Created by Nick Durak on 3/13/14.
//  Copyright (c) 2014 Nick Durak. All rights reserved.
//

#ifndef __CSE335_Proj03__EvaluateVisitor__
#define __CSE335_Proj03__EvaluateVisitor__

#include <iostream>
#include <stack>
#include "LogicExprVisitor.h"
#include "Literal.h"
#include "Negate.h"
#include "Variable.h"
#include "And.h"
#include "Or.h"
#include "Implication.h"
#include "Equivalence.h"

class EvaluateVisitor: public LogicExprVisitor
{
private:
    std::stack<bool> m_myStack;
public:
    bool getValue();
    
    virtual void visitLiteral(Literal* lit);
    virtual void visitNegate(Negate* neg);
    virtual void visitVariable(Variable* var);
    virtual void visitAnd(And* a);
    virtual void visitOr(Or* o);
    virtual void visitImplication(Implication* impl);
    virtual void visitEquivalence(Equivalence* equiv);
    
};

#endif /* defined(__CSE335_Proj03__EvaluateVisitor__) */
