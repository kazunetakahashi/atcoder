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

const int C = 1e5 + 10;

int main () {
  int N, Q;
  cin >> N >> Q;
  pair<int, int> pass[C]; // cost, parent
  vector<int> children[C];
  /*for (auto i=0; i<C; i++) {
    children[i] = vector<int>(0);
    }*/
  pass[0] = make_pair(0, 0);
  for (auto i=1; i<N; i++) {
    cin >> pass[i].second >> pass[i].first;
    pass[i].second--;
    children[pass[i].second].push_back(i);
  }
  int x[C];
  for (auto i=0; i<Q; i++) {
    cin >> x[i];
    x[i]--;
  }
  bool isleaf[C];
  fill(isleaf, isleaf+C, true);
  for (auto i=0; i<N; i++) {
    isleaf[pass[i].second] = false;
  }
  int dist[C];
  dist[0] = 0;
  stack<int> S;
  S.push(0);
  while (!S.empty()) {
    int now = S.top();
    S.pop();
    // cerr << "now = " << now << endl;
    dist[now] = dist[pass[now].second] + pass[now].first;
    cerr << "dist[" << now << "] = " << dist[now] << endl;
    for (auto i=0; i<children[now].size(); i++) {
      S.push(children[now][i]);
    }
  }  
  set <pair<int, int> > leaves; // cost, node
  for (auto i=0; i<N; i++) {
    if (isleaf[i]) {
      leaves.insert(make_pair(dist[i], i));
    }
  }
  bool cut[C];
  fill(cut, cut+C, false);
  for (auto i=0; i<Q; i++) {
    int st = x[i];
    if (!cut[st]) {
      S.push(st);
      while (!S.empty()) {
	int now = S.top();
	S.pop();
	if (!cut[now]) {
	  cut[now] = true;
	  cerr << "cut: " << now << endl;
	  for (auto j=0; j<children[now].size(); j++) {
	    S.push(children[now][j]);
	  }
	  if (children[now].empty()) {
	    leaves.erase(make_pair(dist[now], now));
	  }
	}
      }
    }
    if (leaves.empty()) {
      cout << -1 << endl;
    } else {
      cout << leaves.lower_bound(make_pair(-1,0))->first << endl;
    }
  }
}
