#include <bits/stdc++.h>
using namespace std;

int main () {
  stack<int> opes;
  string input;
  
  while (cin >> input) {
    if (input[0] == '+') {
      int a = opes.top();
      opes.pop();
      int b = opes.top();
      opes.pop();
      opes.push(b + a);
    } else if (input[0] == '-') {
      int a = opes.top();
      opes.pop();
      int b = opes.top();
      opes.pop();
      opes.push(b - a);
    } else if (input[0] == '*') {
      int a = opes.top();
      opes.pop();
      int b = opes.top();
      opes.pop();
      opes.push(b * a);
    } else {
      opes.push(atoi(input.c_str()));
    }
  }
  cout << opes.top() << endl;
}