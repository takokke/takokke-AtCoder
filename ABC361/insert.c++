#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
  int n,k,x;
  
  cin >> n;
  cin >> k;
  cin >> x;
  
  
  vector<int> A(n+1);
  A[k] = x;
  for (int i = 0; i < k; ++i) {
    cin >> A[i];
  }
  
  for (int i = k+1; i < n+1; ++i) {
    cin >> A[i];
  }
  
  for (int i = 0; i < n+1; ++i) {
    cout << A[i] << " ";
  }
}