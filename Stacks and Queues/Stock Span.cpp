// 1. You are given a number n, representing the size of array a.
// 2. You are given n numbers, representing the prices of a share on n days.
// 3. You are required to find the stock span for n days.
// 4. Stock span is defined as the number of days passed between the current day and the first day before today when price was higher than today.

// e.g.
// for the array [2 5 9 3 1 12 6 8 7]
// span for 2 is 1
// span for 5 is 2
// span for 9 is 3
// span for 3 is 1
// span for 1 is 1
// span for 12 is 6
// span for 6 is 1
// span for 8 is 2
// span for 7 is 1

#include <iostream>
#include <stack>
using namespace std;

void stock(int arr[], int n)
{
  stack<int> stack;
  stack.push(1);
  int ans[n];
  ans[1] = 1;
  for (int i = 2 ; i <= n ; i++)
  {
    while (stack.size() > 0 && arr[stack.top()] < arr[i])
    {
      stack.pop();
    }
    if (stack.empty())
    {
      ans[i] = i;
    }
    else
    {
      ans[i] = i - stack.top();
    }
    stack.push(i);
  }
  for (int i = 1 ; i <= n  ; i++)
  {
    cout << ans[i] << "\n";
  }
}
int main()
{
  int n;
  cin >> n;
  int arr[n];
  for (int i = 1 ; i <= n ; i++)
  {
    cin >> arr[i];
  }
  stock(arr, n);
}
