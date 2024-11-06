#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <cmath>
#include <cctype>
#include <map>

using namespace std;

// 定义运算符优先级
int getPrecedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

// 执行简单的运算
double applyOp(double a, double b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return b == 0 ? NAN : a / b;
    }
    return 0;
}
bool infixToPostfix(const string &expr, string &postfix)
{
    stack<char> ops;
    bool lastoperator = true;
    bool laste = false;
    bool sign = false;
    for (size_t i = 0; i < expr.size(); ++i)
    {
        char c = expr[i];
        if (isdigit(c) && sign)
        {
            postfix += ' ';
            postfix += '-';
            sign = false;
            laste = false;
        }
        if (isdigit(c) || c == '.')
        {
            postfix += c;
            lastoperator = false;
            laste = false;
        }
        else if ((!laste) && (c == 'e' || c == 'E'))
        {
            postfix += c;
            lastoperator = false;
            laste = true;
            if (i + 1 < expr.size() && expr[i + 1] == '-')
            {
                postfix += expr[++i];
            }
        }
        else if (c == '(')
        {
            ops.push(c);
            lastoperator = true;
            laste = false;
        }
        else if (c == ')')
        {
            while (!ops.empty() && ops.top() != '(')
            {
                postfix += ' ';
                postfix += ops.top();
                ops.pop();
            }
            if (ops.empty())
                return false;
            ops.pop();
            lastoperator = false;
            laste = false;
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/')
        {
            if ((lastoperator) && (c == '-'))
            {
                sign = true;
                laste = false;
            }
            else
            {
                postfix += ' ';
                while (!ops.empty() && getPrecedence(ops.top()) >= getPrecedence(c))
                {
                    postfix += ops.top();
                    postfix += ' ';
                    ops.pop();
                }
                ops.push(c);
                lastoperator = true;
                laste = false;
            }
        }
        else if (!isspace(c))
        {
            // 非法字符
            return false;
        }
    }

    // 处理剩余的操作符
    while (!ops.empty())
    {
        if (ops.top() == '(')
            return false; // 括号不匹配
        postfix += ' ';
        postfix += ops.top();
        ops.pop();
    }
    return true;
}
bool evaluatePostfix(const string &postfix, double &result)
{
    stack<double> values;
    istringstream tokens(postfix);
    string token;

    while (tokens >> token)
    {
        if (isdigit(token[0]) || (token[0] == '-' && token.size() > 1))
        { // 数字处理
            values.push(stod(token));
        }
        else if (token.size() == 1 && string("+-*/").find(token[0]) != string::npos)
        { // 运算符处理
            if (values.size() < 2)
                return false;
            double b = values.top();
            values.pop();
            double a = values.top();
            values.pop();
            double res = applyOp(a, b, token[0]);
            if (isnan(res))
                return false;
            values.push(res);
        }
        else
        {
            return false;
        }
    }

    if (values.size() != 1)
        return false;
    result = values.top();
    return true;
}