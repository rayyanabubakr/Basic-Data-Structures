// 1. You are given a string exp representing an expression.
// 2. You are required to check if the expression is balanced i.e. closing brackets and opening brackets match up well.

// e.g.
// [(a + b) + {(c + d) * (e / f)}] -> true
// [(a + b) + {(c + d) * (e / f)]} -> false
// [(a + b) + {(c + d) * (e / f)} -> false
// ([(a + b) + {(c + d) * (e / f)}] -> false

#include <stack>
#include <iostream>
using namespace std;

int main()
{
    stack<char> stack;
    string str;
    getline(cin, str);
    int n = str.length(), f = 0;
    for(int i = 0; i < n ; i++)
    {
        if(str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            stack.push(str[i]);
        }
        else if(str[i] == ')' || str[i] == '}' || str[i] == ']')
        {
            if(stack.empty())
            {
                f = 1;
                break;
            }
            if(str[i] == ')' && stack.top() != '(')
            {
                f = 1;
                break;
            }
            else if(str[i] == '}' && stack.top() != '{')
            {
                f = 1;
                break;
            }
            else if(str[i] == ']' && stack.top() != '[')
            {
                f = 1;
                break;
            }
            else
            {
                stack.pop();
            }
        }
    }
    if(!stack.empty())
    {
        f = 1;
    }
    f == 1 ? cout << "false" : cout << "true";

}
