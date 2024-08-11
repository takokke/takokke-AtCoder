#include <bits/stdc++.h>
using namespace std;

struct Trump {
    char type;
    int value;
    bool operator==(const Trump& other) const {
        return (type == other.type) && (value == other.value);
    }
};

void isStable(vector<Trump> A, vector<Trump>B) {
  if (A == B) {
    cout << "Stable" << endl;
  }else {
    cout << "Not stable" << endl;
  }
}

void showCards(vector<Trump> C) {
  int N = C.size();
  for (int i = 0; i < N; i++) {
    if (i != N-1) {
      cout << C.at(i).type << C.at(i).value << " ";
    } else {
      cout << C.at(i).type << C.at(i).value << endl;
    }
  }
}

// 安定なソート
vector<Trump> bubbleSort(vector<Trump> C, int N) {
  
  for (int i = 0; i < N; i++) {
    for (int j= N-1; j > i; j--) {
      if (C.at(j).value < C.at(j-1).value) {
        Trump work = C.at(j);
        C.at(j) = C.at(j-1);
        C.at(j-1) = work;
      }
    }
  }
  return C;
}

vector<Trump> selectionSort(vector<Trump> C, int N) {
    for (int i = 0; i < N; i++) {
        int minj = i;
        for (int j = i+1; j < N; j++) {
            if (C[minj].value > C[j].value) {
                minj = j;
            }
        }
        if (minj != i) {
            Trump work = C[minj];
            C[minj] = C[i];
            C[i] = work;   
        }
    }
    return C;
}

int main() {
    int N;
    cin >> N;
    vector<Trump> cards(N);
    for (int i = 0; i < N; i++) {
        string card;
        cin >> card;
        cards.at(i).type = card[0];
        cards.at(i).value = int(card[1]-'0');
    }
    
    vector<Trump> bubbleCards(N);
    vector<Trump> selectionCards(N);
    bubbleCards = bubbleSort(cards, N);
    selectionCards = selectionSort(cards, N);
    showCards(bubbleCards);
    cout << "Stable" << endl;
    
    showCards(selectionCards);
    isStable(bubbleCards, selectionCards);
    
    return 0;
}