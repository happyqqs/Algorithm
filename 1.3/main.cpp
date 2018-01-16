//
//  main.cpp
//  Algorithm
//
//  Created by qqs on 15/01/2018.
//  Copyright © 2018 sqq. All rights reserved.
//

#include <iostream>
#include <string>
#include <stack>
#include <math.h>
#include <vector>
using namespace std;

// 双栈算数表达式求值
double evaluate(vector<string> expression)
{
    stack<string> ops = stack<string>();
    stack<double> vals = stack<double>();
    for (int i = 0; i < expression.size(); i++) {
        string p = expression[i];
        if (p == "(") {
            
        } else if (p == "+") {
            ops.push(p);
        } else if (p == "-") {
            ops.push(p);
        } else if (p == "*") {
            ops.push(p);
        } else if (p == "/") {
            ops.push(p);
        } else if (p == "sqrt") {
            ops.push(p);
        } else if (p == ")") {
            // 弹出运算符和操作数，计算结果并压入栈
            string op = ops.top();
            double v = vals.top();
            ops.pop();
            vals.pop();
            if (op == "+") {
                v = vals.top() + v;
                vals.pop();
            } else if (op == "-") {
                v = vals.top() - v;
                vals.pop();
            } else if (op == "*") {
                v = vals.top() * v;
                vals.pop();
            } else if (op == "/") {
                v = vals.top() / v;
                vals.pop();
            } else if (op == "sqrt") {
                v = sqrt(v);
            }
            vals.push(v);
        } else {
            vals.push(stof(p));
        }
    }
    return vals.top();
}

int main(int argc, const char * argv[]) {
    // insert code here...

    string expression[] = {"(", "1", "+", "(", "(", "2", "+", "3", ")", "*", "(", "4", "*", "5", ")", ")", ")", "\0"};
    vector<string> exp = vector<string>();
    int i = 0;
    while (expression[i] != "") {
        exp.push_back(expression[i++]);
    }
    cout<<evaluate(exp)<<endl;
    
    return 0;
}

