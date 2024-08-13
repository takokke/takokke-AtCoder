
// vectorの使用
#include <bits/stdc++.h>
using namespace std;

struct Process{
  string name;
  int time;
};

vector<Process> Q;

void enqueue(Process x) {
    Q.push_back(x);
}


void dequeue() {
    Q.erase(Q.begin());
}

int main () {
    int n;
    cin >> n;
    int q;
    cin >> q;
    int totalTime = 0;
    

    for (int i = 0; i < n; i++) {
      Process p;
      cin >> p.name;
      cin >> p.time;
      Q.push_back(p);
    }
    
    while (Q.size() != 0) {
      Process p = Q.at(0);

      if (p.time - q > 0) {
        p.time = p.time - q;
        
        // 合計処理時間を加算
        totalTime += q;
        // デキュー
        dequeue();
        // エンキュー
        enqueue(p);
      } else {
        // 処理が完了した
        // 合計処理時間を加算
        totalTime += p.time;
        cout << p.name << " " << totalTime << endl;
        // デキュー
        dequeue();
      }
    }

    return 0;
}

// double-ended queue （二重終端キュー、両端キュー）の使用
// こちらの方が速い
// 理由は、vectorのeraseは先頭要素を削除すると、残りの要素を全て先頭にシフトするから。
// 両端キューのpop_frontを用いると解決する。
#include <bits/stdc++.h>
using namespace std;

struct Process{
  string name;
  int time;
};

deque<Process> Q;

void enqueue(Process x) {
    Q.push_back(x);
}


void dequeue() {
    Q.pop_front();
}

int main () {
    int n;
    cin >> n;
    int q;
    cin >> q;
    int totalTime = 0;
    

    for (int i = 0; i < n; i++) {
      Process p;
      cin >> p.name;
      cin >> p.time;
      Q.push_back(p);
    }
    
    while (Q.size() != 0) {
      Process p = Q.front();

      if (p.time - q > 0) {
        p.time = p.time - q;
        
        // 合計処理時間を加算
        totalTime += q;
        // デキュー
        dequeue();
        // エンキュー
        enqueue(p);
      } else {
        // 処理が完了した
        // 合計処理時間を加算
        totalTime += p.time;
        cout << p.name << " " << totalTime << endl;
        // デキュー
        dequeue();
      }
    }

    return 0;
}