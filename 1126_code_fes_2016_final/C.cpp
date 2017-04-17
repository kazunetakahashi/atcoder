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
int M;
int K[100010];
vector<int> L[200100];
bool visited[200100];

int main () {
  cin >> N >> M;
  for (auto i = 0; i < N; i++) {
    cin >> K[i];
    for (auto j = 0; j < K[i]; j++) {
      int l;
      cin >> l;
      L[i].push_back(l+100010);
      L[l+100010].push_back(i);
    }
  }
  fill(visited, visited+200100, false);
  stack<int> S;
  S.push(0);
  while (!S.empty()) {
    int now = S.top();
    S.pop();
    if (!visited[now]) {
      visited[now] = true;
      for (auto x : L[now]) {
        if (!visited[x]) S.push(x);
      }
    }
  }
  for (auto i = 0; i < N; i++) {
    if (!visited[i]) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;  
}
