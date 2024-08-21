#include <bits/stdc++.h>
using namespace std;


// エンキュー
void enqueue(queue< pair<string, int> >& Q, pair<string, int> val) {
  Q.push(val);
}

// デキュー
void dequeue(queue< pair<string, int> >& Q) {
  Q.pop();
}

int main () {
  int n, q;
  cin >> n >> q;
  
  string name;
  int t;
  
  queue< pair<string, int> > Q;
  
  // 入力
  for (int i = 0; i < n; i++) {
    cin >> name >> t;
    enqueue(Q, make_pair(name, t));
  }
  
  int totalTime = 0;
  
  while(!Q.empty()) {
      pair<string, int> u;
      int timeSpent;
      u = Q.front();
      dequeue(Q);
      
      timeSpent = min(u.second, q);
      u.second -= timeSpent;
      totalTime += timeSpent;
      
      if (u.second == 0) {
        cout << u.first << " " << totalTime << endl;
      } else {
        enqueue(Q, u);
      }
      
  }
  
  
  return 0;
}