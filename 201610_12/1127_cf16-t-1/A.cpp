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

typedef tuple<ll, int, int> pass;

int N, M;
vector<pass> V;
int Q;
int S[100010], T[100010];
bool visited[100010];

int main () {
  cin >> N >> M;
  for (auto i = 0; i < M; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--; b--;
    V.push_back(make_tuple(c, a, b));
  }
  cin >> Q;
  for (auto i = 0; i < Q; i++) {
    cin >> S[i] >> T[i];
  }
  sort(V.begin(), V.end());
  fill(visited, visited+100010, false);
  if ()
}
