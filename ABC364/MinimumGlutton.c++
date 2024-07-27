#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  long long x, y; // 今回のきも！
  cin >> n >> x >> y;
  vector<int> a(n);
  vector<int> b(n);
  
  for (int i = 0; i < n; i++) {
    cin >> a.at(i);
  }
  
  for (int i = 0; i < n; i++) {
    cin >> b.at(i);
  }
  
  // A
  sort(a.rbegin(), a.rend());
  
  long long totalA = 0;
  int countA = 0;
  
  for (int i = 0; i < n; i++) {
    totalA = totalA + a.at(i);
    countA++;
    
    if (totalA > x) {
      break;
    }
  }
  
  
  // b
  sort(b.rbegin(), b.rend());
  long long totalB = 0;
  int countB = 0;
  
  for (int i = 0; i < n; i++) {
    totalB = totalB + b.at(i);
    countB++;
    
    if (totalB > y) {
      break;
    }
  }
  
  cout << min(countA, countB) << endl;
  
  
  return 0;
}
