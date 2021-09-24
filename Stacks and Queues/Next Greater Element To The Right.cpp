// 1. You are given a number n, representing the size of array a.
// 2. You are given n numbers, representing elements of array a.
// 3. You are required to "next greater element on the right" for all elements of array
// 4. Input and output is handled for you.

// "Next greater element on the right" of an element x is defined as the first element to right of x having value greater than x.
// Note -> If an element does not have any element on it's right side greater than it, consider -1 as it's "next greater element on right"
// e.g.
// for the array [2 5 9 3 1 12 6 8 7]
// Next greater for 2 is 5
// Next greater for 5 is 9
// Next greater for 9 is 12
// Next greater for 3 is 12
// Next greater for 1 is 12
// Next greater for 12 is -1
// Next greater for 6 is 8
// Next greater for 8 is -1
// Next greater for 7 is -1

#include <iostream>
#include <stack>
using namespace std;

void solve(int arr[] , int n)
{
    stack<int> stack;
    int ans[n];
    ans[n - 1] = -1;
    stack.push(arr[n - 1]);
    for(int i = n- 2; i >= 0; i--){
      while(stack.size() > 0 && arr[i] >= stack.top()){
        stack.pop();
      }     
      if(stack.size() > 0){
        ans[i] = stack.top();
      } else {
        ans[i] = -1;
      }
      
      stack.push(arr[i]);
    }
    for(int i = 0 ; i < n ; i++)
    {
        cout << ans[i] <<"\n";
    }
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0 ; i < n ; i++)
    {
        cin >> arr[i];
    }
    solve(arr, n);
}
