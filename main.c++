#include <bits/stdc++.h>
using namespace std;

int main () {
  int n;
  list<int> L;
  cin >> n;

  string command;
  int x;

  for (int i=0; i < n; i++) {
    cin >> command;
    if (command == "insert") {
      cin >> x;
      L.push_front(x);
    } else if (command == "deleteFirst") {
      L.pop_front();
    } else if (command == "deleteLast") {
      L.pop_back();
    } else {
      cin >> x;
      for (list<int>::iterator it = L.begin(); it != L.end(); it++ ) {
        if (*it == x) {
          L.erase(it);
          break;
        }
      }
    }
  }

  int i = 0;
  for (list<int>::iterator it = L.begin(); it != L.end(); it++) {
    if(i++) cout << " ";
    cout << *it;
  }

  cout << endl;

  return 0;
}