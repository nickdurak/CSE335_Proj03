//
//  SimplifyVisitor.cpp
//  CSE335_Proj03
//
//  Created by Barend Ungrodt on 3/11/14.
//  Copyright (c) 2014 Nick Durak. All rights reserved.
//

#include <iostream>
#include "SimplifyVisitor.h"
#include "Literal.h"
#include "Negate.h"
#include "Variable.h"
#include "BoolExpr.h"
#include "And.h"
#include "Or.h"
#include "Implication.h"
#include "Equivalence.h"

using namespace std;

/*
 if(string_name = "A & false") string_name = "fal4se";
 if(string_name = "false & A") string_name = "false";
 if(string_name = "A & true") string_name = "A";
 if(string_name = "true & A") string_name = "A";
 if(string_name = "A | false") string_name = "A";
 if(string_name = "false | A") string_name = "A";;
 if(string_name = "A | true") string_name = "true";
 if(string_name = "true | A") string_name = "true";
 if(string_name = "A > false") string_name = "~A";
 if(string_name = "false > A") string_name = "true";
 if(string_name = "A > true") string_name = "true";
 if(string_name = "true > A") string_name = "A";
 if(string_name = "A = false") string_name = "~A";
 if(string_name = "false = A") string_name = "~A";
 if(string_name = "A = true") string_name = "A";
 if(string_name = "true = A") string_name = "A";
 */
void SimplifyVisitor::getValue()
{
    if (m_myVector.size() > 0)
    {
        cout << simplified(m_myVector.size() - 1) << endl;
    }
}

string SimplifyVisitor::simplified(int pos)
{
    string result = "(";
    if (!((m_myVector[pos] == "&") || (m_myVector[pos] == "|") || (m_myVector[pos] == ">") || (m_myVector[pos] == "=") || (m_myVector[pos] == "~")))
    {
        result += m_myVector[pos];
        result += " ";
        return result;
    }
    
    if (m_myVector[pos] == "~")
    {
        result += m_myVector[pos];
        result = simplified(--pos);
        result += " ";
        return result;
    }

    result = simplified(--pos);
    result += m_myVector[pos];
    result += " ";
    result = simplified(--pos);
    result += ")";
    return result;

    /*if (pos == 0) return result;
    
    if (!((m_myVector[pos] == "&") || (m_myVector[pos] == "|") || (m_myVector[pos] == ">") || (m_myVector[pos] == "=")))
    {
        result += m_myVector[pos];
        --pos;
    }
    if (pos == 0) return result;
    
    if (m_myVector[pos] == "~")
    {
        result += m_myVector[pos];
        result += simplified(--pos);
        --pos;
    }
    if (pos == 0) return result;
    
    
    result += ")";
    return result;*/
}

bool SimplifyVisitor::stringToBool(std::string const& s)
{
    return (s != "0");
}

string SimplifyVisitor::boolToString(bool const& b)
{
    if (b == 0) return "0";
    return "1";
}

void SimplifyVisitor::visitLiteral(Literal* lit)
{
    if (lit->getValue())
    {
        m_myVector.push_back("1");
        return;
    }
    m_myVector.push_back("0");
}

void SimplifyVisitor::visitVariable(Variable* var)
{
    if (var->getAssigned())
    {
        if (var->getValue())
        {
            m_myVector.push_back("1");
            return;
        }
        m_myVector.push_back("0");
        return;
    }
    m_myVector.push_back(var->getName());
}

void SimplifyVisitor::visitNegate(Negate* neg)
{
    neg->getExpr()->accept(this);
    
    string val = m_myVector.back();
    m_myVector.pop_back();
    
    if ((val == "0") || (val == "1"))
    {
        bool v = stringToBool(val);
        
        m_myVector.push_back(boolToString(!v));
        return;
    }

    m_myVector.push_back(val);
    m_myVector.push_back("~");
}

void SimplifyVisitor::visitAnd(And* a)
{
    a->getRightExpr()->accept(this);
    a->getLeftExpr()->accept(this);
    
    string lval = m_myVector.back();
    m_myVector.pop_back();
    string rval = m_myVector.back();
    m_myVector.pop_back();
    
    if (((lval == "0") || (lval == "1")) && ((rval == "0") || (rval == "1")))
    {
        bool r = stringToBool(rval);
        bool l = stringToBool(lval);
        
        m_myVector.push_back(boolToString(l && r));
        return;
    }
    if (!((lval == "0") || (lval == "1")) && rval == "0")
    {
        m_myVector.push_back("0");
        return;
    }
    if (lval == "0" && !((rval == "0") || (rval == "1")))
    {
        m_myVector.push_back("0");
        return;
    }
    if (!((lval == "0") || (lval == "1")) && rval == "1")
    {
        m_myVector.push_back(lval);
        return;
    }
    if (lval == "1" && !((rval == "0") || (rval == "1")))
    {
        m_myVector.push_back(rval);
        return;
    }
    m_myVector.push_back(rval);
    m_myVector.push_back(lval);
    m_myVector.push_back("&");
}

void SimplifyVisitor::visitOr(Or* o)
{
    o->getRightExpr()->accept(this);
    o->getLeftExpr()->accept(this);

    string lval = m_myVector.back();
    m_myVector.pop_back();
    string rval = m_myVector.back();
    m_myVector.pop_back();
    
    if (((lval == "0") || (lval == "1")) && ((rval == "0") || (rval == "1")))
    {
        bool r = stringToBool(rval);
        bool l = stringToBool(lval);
        
        m_myVector.push_back(boolToString(l || r));
        return;
    }
    if (!((lval == "0") || (lval == "1")) && rval == "0")
    {
        m_myVector.push_back(lval);
        return;
    }
    if (lval == "0" && !((rval == "0") || (rval == "1")))
    {
        m_myVector.push_back(rval);
        return;
    }
    if (!((lval == "0") || (lval == "1")) && rval == "1")
    {
        m_myVector.push_back("1");
        return;
    }
    if (lval == "1" && !((rval == "0") || (rval == "1")))
    {
        m_myVector.push_back("1");
        return;
    }
    m_myVector.push_back(rval);
    m_myVector.push_back(lval);
    m_myVector.push_back("|");
}

void SimplifyVisitor::visitImplication(Implication* impl)
{
    impl->getRightExpr()->accept(this);
    impl->getLeftExpr()->accept(this);

    string lval = m_myVector.back();
    m_myVector.pop_back();
    string rval = m_myVector.back();
    m_myVector.pop_back();
    
    if (((lval == "0") || (lval == "1")) && ((rval == "0") || (rval == "1")))
    {
        bool r = stringToBool(rval);
        bool l = stringToBool(lval);
        
        m_myVector.push_back(boolToString(!l || r));
        return;
    }
    if (!((lval == "0") || (lval == "1")) && rval == "0")
    {
        m_myVector.push_back(lval);
        m_myVector.push_back("~");
        return;
    }
    if (lval == "0" && !((rval == "0") || (rval == "1")))
    {
        m_myVector.push_back("1");
        return;
    }
    if (!((lval == "0") || (lval == "1")) && rval == "1")
    {
        m_myVector.push_back("1");
        return;
    }
    if (lval == "1" && !((rval == "0") || (rval == "1")))
    {
        m_myVector.push_back(rval);
        return;
    }
    m_myVector.push_back(rval);
    m_myVector.push_back(lval);
    m_myVector.push_back(">");
}

void SimplifyVisitor::visitEquivalence(Equivalence* equiv)
{
    equiv->getRightExpr()->accept(this);
    equiv->getLeftExpr()->accept(this);
    
    string lval = m_myVector.back();
    m_myVector.pop_back();
    string rval = m_myVector.back();
    m_myVector.pop_back();
    
    if (((lval == "0") || (lval == "1")) && ((rval == "0") || (rval == "1")))
    {
        bool r = stringToBool(rval);
        bool l = stringToBool(lval);
        
        m_myVector.push_back(boolToString(l == r));
        return;
    }
    if (!((lval == "0") || (lval == "1")) && rval == "0")
    {
        m_myVector.push_back(lval);
        m_myVector.push_back("~");
        return;
    }
    if (lval == "0" && !((rval == "0") || (rval == "1")))
    {
        m_myVector.push_back(rval);
        m_myVector.push_back("~");
        return;
    }
    if (!((lval == "0") || (lval == "1")) && rval == "1")
    {
        m_myVector.push_back(lval);
        return;
    }
    if (lval == "1" && !((rval == "0") || (rval == "1")))
    {
        m_myVector.push_back(rval);
        return;
    }
    m_myVector.push_back(rval);
    m_myVector.push_back(lval);
    m_myVector.push_back("=");
}
