#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N;
char a[210][210];
char b[210][210];
vector<int> V[210];
vector<int> W[210];

int main() {
  while (cin >> N && N > 0) {
    for (auto i=0; i<N; i++) {
      for (auto j=0; j<=i; j++) {
        if (i == j) a[i][j] = '#';
        else if (j == i-1) a[i][j] = '@';
        else a[i][j] = 'o';
      }
    }
    a[2][0] = '@';
    for (auto i=N-1; i>=0; i--) {
      for (auto j=0; j<(N-i); j++) {
        cout << a[i+j][j];
      }
      cout << endl;
    }
    for (auto i=N-1; i>=0; i--) {
      string S;
      cin >> S;
      for (auto j=0; j<(N-i); j++) {
        b[i+j][j] = S[j];
      }
    }
    for (auto i=0; i<N; i++) {
      for (auto j=0; j<i; j++) {
        if (b[i][j] == '@') {
          V[i].push_back(j);
          W[j].push_back(i);
          // cerr << i << " " << j << endl;
        }
      }
    }
    int start;
    int goal;
    bool ok = true;
    for (auto i=0; i<N; i++) {
      if ((int)V[i].size() == 2) start = i;
      if ((int)V[i].size() == 0) goal = i;
    }
    // cerr << start << " and " << goal << endl;
    for (auto x : V[start]) {
      if (x == goal) ok = false;
    }
    if (ok) {
      if (V[V[start][0]][0] != V[start][1]) {
        swap(V[start][0], V[start][1]);
      }
      int now = start;
      while (N > 0) {
        cout << now+1;
        N--;
        if (N > 0) {
          cout << " ";
          now = V[now][0];
        } else {
          cout << endl;
        }
      }
    } else {
      for (auto i=0; i<N; i++) {
        if ((int)W[i].size() == 2) start = i;
        if ((int)W[i].size() == 0) goal = i;
      }
      // cerr << start << " and " << goal << endl;
      if (W[W[start][0]][0] != W[start][1]) {
        swap(W[start][0], W[start][1]);
      }
      int now = start;
      while (N > 0) {
        cout << now+1;
        N--;
        if (N > 0) {
          cout << " ";
          now = W[now][0];
        } else {
          cout << endl;
        }
      }
    }
  }
}
