#include <bits/stdc++.h>
using namespace std;

struct CurrentPoint {
  int i;
  int j;
};
 
int main() {
  int h, w;
  cin >> h >> w;
  CurrentPoint s;
  cin >> s.i >> s.j;
  
  vector<vector<char>> c(h, vector<char>(w));
  
  // グリッド作成
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> c.at(i).at(j);
    }
  }
  
  string x;
  cin >> x;
  for (int k = 0; k < (int)x.size(); k++) {
    if (x.at(k) == 'L') {
      // 現在地の位置jから１引いたとき、０になると左はない
      if (s.j - 1 == 0) {
        continue;
      } else if (c.at(s.i-1).at(s.j-2) == '.') {
        // 左に移動
        s.j = s.j -1;
      }
      
    } else if (x.at(k) == 'R') {
      
      if (s.j == w) {
        continue;
      } else if (c.at(s.i-1).at(s.j) == '.') {
        // 右に移動
        s.j = s.j+1;
      }
      
    } else if (x.at(k) == 'U') {
      if (s.i == 1) {
        continue;
      } else if (c.at(s.i-2).at(s.j-1) == '.') {
        // 上に移動
        s.i = s.i-1;
      }
    } else if (x.at(k) == 'D') {
      if (s.i == h) {
        continue;
      } else if (c.at(s.i).at(s.j-1) == '.') {
        // 下に移動
        s.i = s.i+1;
      }
    }
  }
  
  cout << s.i << " " << s.j << endl;
  
  return 0;
}
