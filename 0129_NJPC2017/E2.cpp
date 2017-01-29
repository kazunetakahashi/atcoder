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

// const int dx[4] = {1, 0, -1, 0};
// const int dy[4] = {0, 1, 0, -1};

// const int C ;
// const ll M = 1000000007;

typedef tuple<int, int, bool> pass;
typedef tuple<int, int, bool> child;

int N, D;
vector<pass> V[100010];
vector<child> children[100010];
int parent[100010];
int dist[100010];
int max_d[100010];
int forbid_c[100010];
int ans_distance[100010];
int ans_forbid[100010];

int max_distance(int root) {
  int ans = 0;
  for (auto x : children[root]) {
    int son = get<0>(x);
    int cost = get<1>(x);
    ans = max(ans, max_distance(son) + cost);
  }
  // cerr << "max_d[" << root << "] = " << ans << endl; 
  return max_d[root] = ans;
}

int forbid_count(int root) {
  int ans = 0;
  for (auto x : children[root]) {
    int son = get<0>(x);
    bool ok = get<2>(x);
    if (ok) {
      ans += forbid_count(son) + 1;
    } else {
      ans += forbid_count(son);
    }
  }
  // cerr << "forbid_c[" << root << "] = " << ans << endl;
  return forbid_c[root] = ans;
}

void make_ans_dist(int root, int d) {
  vector<int> v_dist;
  v_dist.push_back(d);
  v_dist.push_back(0);
  for (auto x : children[root]) {
    int son = get<0>(x);
    int cost = get<1>(x);
    v_dist.push_back(max_d[son] + cost);
  }
  sort(v_dist.begin(), v_dist.end());
  reverse(v_dist.begin(), v_dist.end());
  for (auto x : children[root]) {
    int son = get<0>(x);
    int cost = get<1>(x);
    if (max_d[son] + cost == v_dist[0]) {
      ans_distance[son] = max(max_d[son], v_dist[1] + cost);
      // cerr << "ans_distance[" << son << "] = " << ans_distance[son] << endl;
      make_ans_dist(son, v_dist[1] + cost);
    } else {
      ans_distance[son] = v_dist[0] + cost;
      // cerr << "ans_distance[" << son << "] = " << ans_distance[son] << endl;
      make_ans_dist(son, ans_distance[son]);
    }
  }
}

void make_ans_forbid(int root) {
  for (auto x : children[root]) {
    int son = get<0>(x);
    bool ok = get<2>(x);
    ans_forbid[son] = (ok ? (ans_forbid[root] - 1) : (ans_forbid[root] + 1));
    // cerr << "ans_forbid[" << son << "] = " << ans_forbid[son] << endl;
    make_ans_forbid(son);
  }
}

int main () {
  cin >> N >> D;
  for (auto i = 0; i < N-1; i++) {
    int A, B, C;
    cin >> A >> B >> C;
    A--; B--;
    V[A].push_back(pass(B, C, true));
    V[B].push_back(pass(A, C, false));
  }
  parent[0] = -1;
  fill(dist, dist+N, -1);
  dist[0] = 0;
  stack<int> S;
  S.push(0);
  while (!S.empty()) {
    int from = S.top();
    S.pop();
    for (auto x : V[from]) {
      int to = get<0>(x);
      int cost = get<1>(x);
      if (dist[to] == -1) {
        dist[to] = dist[from] + cost;
        children[from].push_back(x);
        // cerr << to << " is a child of " << from << endl;
        S.push(to);
      } else {
        parent[to] = from;
      }
    }
  }
  ans_distance[0] = max_distance(0);
  ans_forbid[0] = forbid_count(0);
  make_ans_dist(0, 0);
  make_ans_forbid(0);
  int mini = 1000000007;
  for (auto i = 0; i < N; i++) {
    if (ans_distance[i] <= D) {
      if (mini > ans_forbid[i]) {
        mini = ans_forbid[i];
      }
    }
  }
  if (mini < 1000000007) {
    cout << mini << endl;
  } else {
    cout << -1 << endl;
  }
}
