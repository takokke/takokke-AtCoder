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

// 最後の要素を表示(検証用)
void printLast() {
    Node *output = sentinel->prev;
    cout << "末尾の要素: " << output->key << endl;
}

// 先頭に追加
void insert(int key) {
  Node *x;
  x = new Node;
  x->key = key;
  x->prev = sentinel;

  sentinel->next->prev = x; // 正体はこれ！！ init()で、sentinel->nextはsentinelになっている。そのprevを設定することになる

  x->next = sentinel->next;
  sentinel->next = x;
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

void printList() {
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
  printList();
}
