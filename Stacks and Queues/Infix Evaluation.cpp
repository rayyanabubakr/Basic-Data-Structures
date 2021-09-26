// 1. You are given an infix expression.
// 2. You are required to evaluate and print it's value.

#include <iostream>
#include <stack>
using namespace std;

int isgreater(char op)
{
  if (op == '*' || op == '/' )
  {
    return 2;
  }
  else if (op == '+' || op == '-' )
  {
    return 1;
  }
  return 0;
}
float do_op(char op, float a, float b)
{
  switch (op)
  {
    case '+':
      return a + b;
      break;
    case '-':
      return a - b;
      break;
    case '*':
      return a * b;
      break;
    case '/':
      return a / b;
      break;
  }
}
int main()
{
  stack<float> operands;
  stack<char> operators;
  string str;
  getline(cin, str);
  for (int i = 0; i < str.length(); i++)
  {
    if (str[i] == ' ')                                                
    {
      continue;
    }
    else if (isdigit(str[i]))
    {
      operands.push(str[i] - '0');
    }
    else if (str[i] == '(')
    {
      operators.push(str[i]);
    }
    else if (str[i] == ')')
    {
      while (!operators.empty() && operators.top() != '(')
      {
        float s1 = operands.top();
        operands.pop();
        float s2 = operands.top();
        operands.pop();
        char x = operators.top();
        operators.pop();
        float s3 = do_op(x, s2, s1);
        operands.push(s3);
      }
      if(!operators.empty())
      {
        operators.pop();
      }
    }
    else
    {
          while (!operators.empty() && isgreater(operators.top()) >= isgreater(str[i]))
          {
            float s1 = operands.top();
            operands.pop();
            float s2 = operands.top();
            operands.pop();
            char x = operators.top();
            operators.pop();
            float s3 = do_op(x, s2, s1);
            operands.push(s3);
          }
          operators.push(str[i]);
    }
  }
  while (!operators.empty())
  {
    float s1 = operands.top();
    operands.pop();
    float s2 = operands.top();
    operands.pop();
    char x = operators.top();
    operators.pop();
    float s3 = do_op(x, s2, s1);
    operands.push(s3);
  }
  cout <<(int) operands.top();
}
