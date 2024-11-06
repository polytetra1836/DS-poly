#include <iostream>
#include "expression_evaluator.h"
void test(const string &expr)
{
    string postfix;
    double result;
    if (!infixToPostfix(expr, postfix))
    {
        cout << "ILLEGAL" << endl;
        return;
    }

    if (evaluatePostfix(postfix, result))
    {
        cout << result << endl;
    }
    else
    {
        cout << "ILLEGAL" << endl;
    }
}
int main()
{
    string expr;
    cout << "固定测试样例:";
    const string K[100] = {
        "(1+2)*(1+2*(2+2))",
        "1.2*1.2",
        "(1)",
        "(2+2",
        "+2",
        "-2",
        "2-2-",
        "1/0",
        "1++1.2",
        "1+-1.2",
        "2e2-2", "2e-1+1", "2e-2*2"};

    int i;
    for (i = 0; i <= 99; ++i)
    {
        if (K[i].empty())
            break;
        cout << K[i] << " 输出结果为 ：";
        test(K[i]);
    }
    while (true)
    {
        cout << "请自主测试；输入表达式 (输入 'exit' 退出): ";
        getline(cin, expr);

        if (expr == "exit")
        {
            cout << "退出程序." << endl;
            break;
        }
        test(expr);
    }

    return 0;
}