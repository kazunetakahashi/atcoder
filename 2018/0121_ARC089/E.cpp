#include <iostream>
#include <iomanip> // << fixed << setprecision(xxx)
#include <algorithm> // do { } while ( next_permutation(A, A+xxx) ) ;
#include <vector>
#include <string> // to_string(nnn) // substr(m, n) // stoi(nnn)
#include <complex>
#include <tuple> // get<n>(xxx)
#include <queue>
#include <stack>
#include <map> // if (M.find(key) != M.end()) { }
#include <set> // S.insert(M);
// if (S.find(key) != S.end()) { }
// for (auto it=S.begin(); it != S.end(); it++) { }
// auto it = S.lower_bound(M);
#include <random> // random_device rd; mt19937 mt(rd());
#include <cctype>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib> // atoi(xxx)
using namespace std;

#define DEBUG 0 // change 0 -> 1 if we need debug.
// insert #if<tab> by my emacs. #if DEBUG == 1 ... #end

typedef long long ll;

// const int dx[4] = {1, 0, -1, 0};
// const int dy[4] = {0, 1, 0, -1};

// const int C = 1e6+10;
// const ll M = 1000000007;

int A, B;
int d[100][100];
bool ok[100][100];
typedef tuple<int, int, int> path;
vector<path> V;

void answer() {
  cout << 204 << " " << V.size() << endl;
  for (auto x : V) {
    cout << get<0>(x) << " " << get<1>(x) << " ";
    if (get<2>(x) == -1) {
      cout << "X" << endl;
    } else if (get<2>(x) == -2) {
      cout << "Y" << endl;
    } else {
      cout << get<2>(x) << endl;
    }
  }
  cout << 1 << " " << 204 << endl;
}

void add(int i, int j, int a) {
  V.push_back(make_tuple(i+1, 204-j, a));
}

int main () {
  cin >> A >> B;
  for (auto i = 1; i <= A; ++i) {
    for (auto j = 1; j <= B; ++j) {
      cin >> d[i][j];
      ok[i][j] = false;
    }
  }
  for (auto i = 1; i <= 101; ++i) {
    V.push_back(make_tuple(i, i+1, -1));
  }
  for (auto i = 103; i <= 203; ++i) {
    V.push_back(make_tuple(i, i+1, -2));
  }
  for (auto i = 0; i <= 101; ++i) {
    for (auto j = 0; j <= 101; ++j) {
      int a = 0;
      for (auto X = 1; X <= A; ++X) {
        for (auto Y = 1; Y <= B; ++Y) {
          a = max(a, d[X][Y] - i * X - j * Y);
        }
      }
      add(i, j, a);
      for (auto X = 1; X <= A; ++X) {
        for (auto Y = 1; Y <= B; ++Y) {
          if (d[X][Y] == a + i * X + j * Y) {
            ok[X][Y] = true;
          }
        }
      }
    }
  }
  for (auto X = 1; X <= A; ++X) {
    for (auto Y = 1; Y <= B; ++Y) {
      if (!ok[X][Y]) {
        cout << "Impossible" << endl;
        return 0;
      }
    }
  }
  cout << "Possible" << endl;
  answer();
}
