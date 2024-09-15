#include <bits/stdc++.h>
using namespace std;

int cnt = 0;


bool binarySort (vector<int> &S, int n, int key) {
  int right = n;
  int left = 0;
  while (left < right) {
    int mid = (left + right) / 2;

    if (S.at(mid) == key) {
     
      cnt++;
      return true;
    } else if (S.at(mid) < key) {
      
      left = mid+1;
    } else {
      
      right = mid;
    }
  }

  return false;
}

int main () {
  int n, q;
  cin >> n;

  vector<int> S(n);

  for (int i = 0; i < n; i++) {
    cin >> S.at(i);
  }

  cin >> q;

  int t;
  for (int i = 0; i < q; i++) {
    cin >> t;
    binarySort(S, n, t);
  }

  cout << cnt << endl;
  return 0;
}