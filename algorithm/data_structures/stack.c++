#include <bits/stdc++.h>
using namespace std;


bool isEmpty(vector<int>& S) {
  return S.size() == 0;
}

void push(vector<int>& S, int x) {
  S.push_back(x);
}

int pop(vector<int>& S) {
    if (isEmpty(S)) {
      cerr << "Error: under flow " << endl;
      exit(EXIT_FAILURE);
    }
    int v = S.back();
    S.pop_back();
    return v;
}


int main() {
  vector<int> S;
  string input;
  
  while (cin >> input) {
    if (input == "+") {
      int a = pop(S);
      int b = pop(S);
      push(S, b + a);
    } else if (input == "-") {
      int a = pop(S);
      int b = pop(S);
      push(S, b - a);
    } else if (input == "*") {
      int a = pop(S);
      int b = pop(S);
      push(S, b * a);
    } else {
      int ope = stoi(input);
      push(S, ope);
    }
  }
  
  // 入力を確認
  cout << S.at(0) << endl;

  return 0;
}