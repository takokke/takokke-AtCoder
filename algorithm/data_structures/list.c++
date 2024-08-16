#include <bits/stdc++.h>
using namespace std;

struct Node {
  int key;
  Node* next;
  Node* prev;
};


// 番兵
Node *sentinel;

void init() {
  sentinel = new Node;
  sentinel->next = sentinel;
  sentinel->prev = sentinel;
}

void insert(int key) {
  Node *x;
  x = new Node;
  x->key = key;
  x->prev = sentinel;
  x->next = sentinel->next;
  sentinel->next->prev = x;
  sentinel->next = x;
  
  if (sentinel->prev == sentinel) {
    sentinel->prev = x;
  }
}

void deleteFirst () {
  if (sentinel->next == sentinel) return; // リストが空の場合
  Node *firstPtr = sentinel->next;
  firstPtr->next->prev = sentinel;
  sentinel->next = firstPtr->next;
  delete firstPtr;
}

void deleteLast() {
  if (sentinel->prev == sentinel) return; // リストが空の場合
  Node *lastPtr = sentinel->prev;
  lastPtr->prev->next = sentinel;
  sentinel->prev = lastPtr->prev;
  delete lastPtr;
}

void deleteNode(int key) {
  Node *x = sentinel->next;
  while (x != sentinel && x->key != key) {
    x = x->next;
  }
  if (x != sentinel) {
    x->prev->next = x->next;
    x->next->prev = x->prev;
    delete x;
  }
}

int main() {
  int n;
  cin >> n;
  string com;

  init();
  for (int i = 0; i < n; i++) {
    cin >> com;
    if (com == "insert") {
      int x;
      cin >> x;
      insert(x);
    } else if (com == "deleteFirst") {
      deleteFirst();
    } else if (com == "deleteLast") {
      deleteLast();
    } else if (com == "delete") {
      int y;
      cin >> y;
      deleteNode(y);
    }
  }

  // 出力
  Node *output = sentinel->next;
  int isf = 0;
  while (output != sentinel) {
    if (isf++ > 0) {
      cout << " ";
    }
    cout << output->key;
    output = output->next;
  }
  cout << endl;
}
