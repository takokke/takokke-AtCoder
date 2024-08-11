#include <bits/stdc++.h>
using namespace std;

// iとminjが一緒の時交換しない
void selectionSort(vector<int>& A, int N) {
    int count = 0;
    for (int i = 0; i < N; i++) {
        int minj = i;
        for (int j = i+1; j < N; j++) {
            if (A.at(j) < A.at(minj)) {
                minj = j;
            }
        }
        if (i != minj) {
            int work = A.at(i);
            A.at(i) = A.at(minj);
            A.at(minj) = work;
            count++;
        }
    }
    for (int i = 0; i < N; i++) {
        cout << A.at(i);
        if (i != N-1) {
            cout << " ";
        } else {
            cout << endl;
        }
    }
    cout << count << endl;
}

int main () {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A.at(i);
    }
    selectionSort(A, N);
}