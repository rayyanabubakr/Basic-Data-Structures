// 1. You are given an infix expression.
// 2. You are required to convert it to postfix and print it.
// 3. You are required to convert it to prefix and print it.

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
string reverse(string str)
{
    string rev="";
    for(int i = str.length() - 1; i >=0 ; i--)
    {
        if(str[i] == '(')
        {
            rev += ')';
        }
        else if(str[i] == ')')
        {
            rev+= '(';
        }
        else
        {
            rev+= str[i];
        }
    }
    return rev;
}
void postfix(string str)
{
  stack<char> operators;
  string ans = "";
  for (int i = 0; i < str.length(); i++)
  {
    if (isalpha(str[i]))
    {
      ans += str[i];
    }
    else if (str[i] == '(')
    {
      operators.push(str[i]);
    }
    else if (str[i] == ')')
    {
      while (!operators.empty() && operators.top() != '(')
      {
        ans += operators.top();
        operators.pop();
      }
      if (!operators.empty())
      {
        operators.pop();
      }
    }
    else
    {
      while (!operators.empty() && isgreater(operators.top()) >= isgreater(str[i]))
      {
        ans += operators.top();
        operators.pop();
      }
      operators.push(str[i]);
    }
  }
  while (!operators.empty())
  {
    ans += operators.top();
    operators.pop();
  }
  cout << ans;
}
void prefix(string str)
{
  stack<char> operators;
  string ans = "";
  str = reverse(str);
  for (int i = 0; i < str.length(); i++)
  {
    if (isalpha(str[i]))
    {
      ans += str[i];
    }
    else if (str[i] == '(')
    {
      operators.push(str[i]);
    }
    else if (str[i] == ')')
    {
      while (!operators.empty() && operators.top() != '(')
      {
        ans += operators.top();
        operators.pop();
      }
      if (!operators.empty())
      {
        operators.pop();
      }
    }
    else
    {
      while (!operators.empty() && isgreater(operators.top()) > isgreater(str[i]))
      {
        ans += operators.top();
        operators.pop();
      }
      operators.push(str[i]);
    }
  }
  while (!operators.empty())
  {
    ans += operators.top();
    operators.pop();
  }
  ans = reverse(ans);
  cout << ans ;

}
int main()
{
  string str;
  getline(cin, str);
  postfix(str);
  cout << "\n";
  prefix(str);
}
