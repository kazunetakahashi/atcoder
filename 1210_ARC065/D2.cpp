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
#include <cctype>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib> // atoi(xxx)
using namespace std;

typedef long long ll;

//const int dx[4] = {1, 0, -1, 0};
//const int dy[4] = {0, 1, 0, -1};

// const int C ;
// const int M = 1000000007;

typedef pair<int, int> point;

int N;
int K[2];
vector<int> V[2][200010];
bool visited[2][200010];
int group[2][200010];
map<point, int> M;
int ans[200010];

int main () {
  cin >> N >> K[0] >> K[1];
  fill(&visited[0][0], &visited[0][0]+200010*2, false);
  for (auto k = 0; k < 2; k++) {
    for (auto i = 0; i < K[k]; i++) {
      int p, q;
      cin >> p >> q;
      p--; q--;
      V[k][p].push_back(q);
      V[k][q].push_back(p);
    }
    for (auto i = 0; i < N; i++) {
      if (visited[k][i]) continue;
      stack<int> St;
      St.push(i);
      while (!St.empty()) {
        int src = St.top();
        St.pop();
        if (!visited[k][src]) {
          visited[k][src] = true;
          group[k][src] = i;
          for (auto dst : V[k][src]) {
            if (!visited[k][dst]) {
              St.push(dst);
            }
          }
        }
      }
    }
  }
  for (auto i = 0; i < N; i++) {
    point p = make_pair(group[0][i], group[1][i]);
    //cerr << "i = " << i << ", (" << group[0][i] << ", " << group[1][i]
    //     << ")" << endl;
    if (M.find(p) == M.end()) {
      M[p] = 1;
    } else {
      M[p]++;
    }
  }
  for (auto i = 0; i < N; i++) {
    point p = make_pair(group[0][i], group[1][i]);
    ans[i] = M[p];
  }
  for (auto i = 0; i < N; i++) {
    cout << ans[i];
    if (i < N-1) {
      cout << " ";
    } else {
      cout << endl;
    }
  }
}
