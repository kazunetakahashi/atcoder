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

typedef pair<int, int> path;

void encode() {
  int N, M;
  cin >> N >> M;
  bool pass[110][110];
  fill(&pass[0][0], &pass[0][0]+110*110, false);
  int a[110], b[110];
  for (auto i = 0; i < M; ++i) {
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
    pass[a[i]][b[i]] = true;
    pass[b[i]][a[i]] = true;
  }
  vector<int> V[110];
  for (auto i = 0; i < N; ++i) {
    for (auto j = 0; j < N; ++j) {
      if (i == j) continue;
      if (!pass[i][j]) {
        V[i].push_back(j);
      }
    }
  }
  ll X;
  cin >> X;
  bool bit[62];
  bool isone = true;
  fill(bit, bit+62, false);
  int cnt = 0;
  for (auto i = 0; i < 60; ++i) {
    if (((X >> i) & 1) == 1) {
      bit[i] = true;
      ++cnt;
    }
  }
  isone = (cnt <= 30);
  if (!isone) {
    for (auto i = 0; i < 60; ++i) {
      bit[i] = !bit[i];
    }
  }
  random_device rd; mt19937 mt(rd());
  vector<path> ans;
  bool visited[110];
  int forbid = 0;
  int mini = 1000;
  for (auto i = 0; i < N; ++i) {
    if ((int)V[i].size() < mini) {
      forbid = i;
      mini = V[i].size();
    }
  }
  while (true) {
    bool failed = false;
    ans.clear();
    fill(visited, visited+110, false);
    visited[forbid] = true;
    int root = mt()%N;
    if (visited[root]) continue;
    visited[root] = true;
    if (V[root].size() < 5) continue;
    random_shuffle(V[root].begin(), V[root].end());
    int num = (isone ? 3 : 4);
    for (auto i = 0; i < num; ++i) {
      ans.push_back(path(root, V[root][i]));
      if (visited[V[root][i]]) {
        failed = true;
        break;
      }
      visited[V[root][i]] = true;
    }
    if (failed) continue;
    ans.push_back(path(root, V[root][num]));
    int now = V[root][num];
    if (visited[now]) continue;
    visited[now] = true;
    for (auto i = 0; i < 62; ++i) {
      if (bit[i]) {
        num = 2;
      } else {
        num = 1;
      }
      if (i >= 60) num = 1;
      random_shuffle(V[now].begin(), V[now].end());
      int cnt = 0;
      for (auto x : V[now]) {
        if (!visited[x]) {
          visited[x] = true;
          ans.push_back(path(now, x));
          cnt++;
          if (cnt == num) {
            now = x;
            break;
          }
        }
      }
      if (cnt < num) {
        failed = true;
        break;
      }
    }
    if (failed) {
      continue;
    } else {
      cout << ans.size() << endl;
      for (auto x : ans) {
        cout << x.first+1 << " " << x.second+1 << endl;
      }
      return;
    }
  }
}

void decode() {
  int N, A;
  cin >> N >> A;
  int c[5000];
  int d[5000];
  vector<int> V[110];
  for (auto i = 0; i < A; ++i) {
    cin >> c[i] >> d[i];
    c[i]--;
    d[i]--;
    V[c[i]].push_back(d[i]);
    V[d[i]].push_back(c[i]);    
  }
  int root = -1;
  bool isone = true;
  for (auto i = 0; i < N; ++i) {
    if ((int)V[i].size() >= 4) {
      root = i;
      break;
    }
  }
  // cerr << "V[" << root << "].size() = " << V[root].size() << endl;
  /*
  for (auto x : V[root]) {
    cerr << x << " ";
  }
  cerr << endl;
  */
  if ((int)V[root].size() == 4) {
    isone = true;
  } else {
    isone = false;
  }
  // cerr << "isone = " << isone << endl;
  assert(root >= 0);
  int now = 0;
  for (auto x : V[root]) {
    if (V[x].size() > 1) {
      now = x;
      break;
    }
  }
  assert(now >= 0);
  ll ans = 0;
  bool visited[110];
  fill(visited, visited+110, false);
  visited[root] = true;
  for (auto i = 0; i < 60; ++i) {
    visited[now] = true;
    // cerr << "V[" << now << "].size() = " << V[now].size() << endl;
    if ((V[now].size() == 3 && isone)
        || (V[now].size() == 2 && !isone)) {
      ans += ((ll)1 << i);
    }
    for (auto x : V[now]) {
      if (!visited[x] && V[x].size() >= 2) {
        now = x;
        break;
      }
    }
  }
  cout << ans << endl;
}

int main () {
  string s;
  cin >> s;
  if (s == "encode") {
    encode();
  } else {
    decode();
  }
}
