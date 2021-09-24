
// 1. You are given a string exp representing an expression.
// 2. Assume that the expression is balanced  i.e. the opening and closing brackets match with each other.
// 3. But, some of the pair of brackets maybe extra/needless. 
// 4. You are required to print true if you detect extra brackets and false otherwise.

// e.g.'
// ((a + b) + (c + d)) -> false
// (a + b) + ((c + d)) -> true

#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main() 
{
    stack<char> stack;
    string str;
    getline(cin, str);
    int n = str.length(), f = 0;
    for(int i = 0 ; i < n ; i ++)
    {
        if(str[i] == ')')
        {
            if(stack.top() == '(')
            {
                f = 1;
                break;
            }
            else
            {
                while(stack.top() != '(')
                {
                    stack.pop();
                }
                stack.pop();
            }
        }
        else
        {
            stack.push(str[i]);
        }
    }
    f == 1 ? cout <<"true" : cout <<"false";
}
