//
//  main.cpp
//  CSE335_Proj03
//
//  Created by Nick Durak on 3/11/14.
//  Copyright (c) 2014 Nick Durak. All rights reserved.
//

#include <iostream>
#include "LogicExprVisitor.h"
#include "PrintVisitor.h"
#include "SimplifyVisitor.h"
#include "EvaluateVisitor.h"
#include "Literal.h"
#include "Negate.h"
#include "Variable.h"
#include "BoolExpr.h"
#include "And.h"
#include "Or.h"
#include "Implication.h"
#include "Equivalence.h"

using namespace std;

int main(int argc, const char * argv[])
{
    LogicExpr* ex = new Or(new And(new Negate(new Implication(new Literal(true), new Literal(false))), new Equivalence(new Literal(true), new Literal(false))), new Literal(false));
    
    //LogicExprVisitor* pv = new PrintVisitor();
    //LogicExprVisitor* ev = new EvaluateVisitor();
    EvaluateVisitor ev;
    PrintVisitor pv;
    cout.setf(ios::boolalpha);
    
    ex->accept(&pv);
    
    ex->accept(&ev);
    
    //bool result = ev.getValue();
    cout << " Evaluates to ";
    cout << ev.getValue() << ".\n";

    delete ex;
 //   delete pv;
   // delete ev;
}

