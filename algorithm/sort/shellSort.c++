#include <bits/stdc++.h>
using namespace std;

// cntは\lceil{n^1.5}\rceilを超えてはならない
// つまり、最悪計算量がn^1.5を超えてはダメ
// 間隔を表す数列は、(3^k-1)/2、\lceil{n/3}\rceil

int cnt = 0;

// 挿入ソート
void insertionSort(vector<int>& A, int n, int g) {
  for (int i = g; i < n; i++) {
    int v = A.at(i);
    int j = i - g;
    while (j >= 0 && A.at(j) > v) {
      A.at(j+g) = A.at(j);
      j = j - g;
      cnt++;
    }
    A.at(j+g) = v;
  }
}

void shellSort(vector<int>& A, int n) {
  vector<int> G;
  
  int m = 0;
  int max = (n+3-1) / 3;
  
  // 数列を作る。^は排他的論理和のため使えない。
  // べき乗はpow関数を使う
  for (int k = 1; (pow(3, k)-1)/2 <= max ; k++) {
    G.push_back((pow(3, k)-1)/2);
    m++;
  }
  cout << m << endl;
  
  for (int i = m-1; i >= 0; i--) {
    insertionSort(A, n, G.at(i));
    if (i != 0) {
      cout << G.at(i) << " ";
    } else {
      cout << G.at(i)  << endl;
    }
  }
  
  cout << cnt << endl;
  
  for (int i = 0; i < n; i++) {
    cout << A.at(i) << endl;
  }
}

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A.at(i);
    }
    shellSort(A, n);
    return 0;
}