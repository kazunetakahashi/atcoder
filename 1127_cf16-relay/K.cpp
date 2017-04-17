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

int N;
vector<int> V[100010];
vector<int> child[100010];
int parent[100010];
int visited[100010];
int dp[2][100010];

int main () {
  cin >> N;
  for (auto i = 0; i < N; i++) {
    int p, q;
    cin >> p >> q;
    p--; q--;
    V[p].push_back(q);
    V[q].push_back(p);
  }
  parent[0] = -1;
  stack<int> S;
  S.push(0);
  fill(visited, visited+100010, 0);
  while (!S.empty()) {
    int now = S.top();
    S.pop();
    if (visited[now] == 0) {
      visited[now]++;
      for (auto x : V[now]) {
        if (visited[x] == 0) {
          S.push(x);
          child[now].push_back(x);
        }
      }
    } else if (visited[now] == 1) {
      visited[now]++;
      for (auto x : V[now]) {
        parent[x] = now;
      }
    }
  }
  
}
