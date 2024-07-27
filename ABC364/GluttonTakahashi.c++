#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  vector<string> S(N);
  bool nauseous = false;
  
  for (int i = 0; i < N; i++) {
    
    if (nauseous) {
      cout << "No";
      return 0;
    }
    
    cin >> S.at(i);
    if (i != 0 && S.at(i-1) == "sweet" && S.at(i) == "sweet") {
      nauseous = true;
    }
  }
  
  cout << "Yes";
  
  return 0;
}
