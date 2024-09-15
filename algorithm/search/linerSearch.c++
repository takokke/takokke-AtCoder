#include <bits/stdc++.h>
using namespace std;

bool linearSearch (vector<int> S, int key,int n) {

  S.push_back(key);
  int i = 0;
  while (S.at(i) != key) {
    i++;
  }

  return n != i;
}

int main () {
  int n;
  cin >> n;

  vector<int> S(n);;

  for (int i = 0; i < n; i++) {
    cin >> S.at(i);
  }

  int q;
  cin >> q;

  int T;
  int count = 0;

  for (int i = 0; i < q; i++) {
    cin >> T;
    if (linearSearch(S, T, n)) count++;
  }


  cout << count << endl;

  return 0;
}