#include <iostream>
#include <stack>
using namespace std;

int priority(char alpha) {
    if (alpha == '+' || alpha == '-')
        return 1;

    if (alpha == '*' || alpha == '/')
        return 2;

    return 0;
}
string convertRPN(string input)
{
    int i = 0;
    string Answer = "";
    stack <int>opr;

    while (input[i] != '\0')
    {
        if (input[i] >= '0' && input[i] <= '9')
        {
            Answer += input[i];
            i++;
        }
   
        else if (input[i] == '(')
        {
            opr.push(input[i]);
            i++;
        }
        else if (input[i] == ')')
        {
            while (opr.top() != '(') {
                Answer += opr.top();
                opr.pop();
            }
            opr.pop();
            i++;
        }
        else
        {
            while (!opr.empty() && priority(input[i]) <= priority(opr.top())) {
                Answer += opr.top();
                opr.pop();
            }
            opr.push(input[i]);
            i++;
        }
    }
    while (!opr.empty()) {
        Answer += opr.top();
        opr.pop();
    }


    cout << "RPN is : " << Answer << endl;
    return Answer;
}
int Calculate(string RPN)
{
    stack<int> stack;
    for (int i = 0; i < RPN.size(); i++)
    {
        if (RPN[i] >= '0' && RPN[i] <= '9')
        {
            int s = RPN[i] - '0';
            stack.push(s);
        }
        else
        {
            int op2 = stack.top();
            stack.pop();
            int op1 = stack.top();
            stack.pop();
            if (RPN[i] == '+')
                stack.push(op1 + op2);
            if (RPN[i] == '-')
                stack.push(op1 - op2);
            if (RPN[i] == '*')
                stack.push(op1*op2);
            if (RPN[i] == '/')
                stack.push(op1/op2);
        }
      
    }
    return stack.top();
}

int main()
{
    string input;
    cout<<"Enter expression: ";
    cin>>input;
    string Answer;
    Answer = convertRPN(input);
    cout << "answer is: " << Calculate(Answer);
    return 0;
}
