#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <stack>
#include <map>
#include <string>
#include <iterator>
using namespace std;

const int MAX_SIZE = 200010;

// 入力先
int N; // 頂点の数
vector<int> graph_pass[MAX_SIZE]; // 隣接リストで連結グラフを入れておく。
int root = 0; // 根を指定する場合はここに書く。

/*
  辺には2種類ある。
  1. 親子関係を結ぶ辺
  2. その他(backedge)
  1.は、親へ向かう方向と、子に向かう方向を厳密に区別する。
  2.は、階層が上がる方向と、下がる方向を区別する。
 */

// 作業用 
stack<int> S_lowest;
int visit[MAX_SIZE]; // 頂点を訪れた回数
int depth[MAX_SIZE]; // 深さ優先探索の階数
int parent[MAX_SIZE]; // 親
int lowest[MAX_SIZE]; // 子へ向かう方向とbackedgeで上がる方向を辿っていける最上階。つまり、親へ向かう方向は辿れない。

vector<int> odd_renketsu;

// 解答入力先
bool iskansetsu[MAX_SIZE];
vector<int> kansetsu_v;
vector<int> graph_tree[MAX_SIZE]; // backpassを削除したもの

void calc_lowest() {
  S_lowest.push(root);
  parent[root] = -1;
  fill(visit, visit+N, 0);
  fill(lowest, lowest+N, -1);
  while (!S_lowest.empty()) {
    int node = S_lowest.top();
    S_lowest.pop();
    if (visit[node] == 0) { // 普通に深さ優先探索をする。
      visit[node]++;
      depth[node] = ((parent[node] >= 0) ? depth[parent[node]]+1 : 0);
      S_lowest.push(node);
      for (auto child : graph_pass[node]) {
        if (visit[child] == 0) {
          S_lowest.push(child); // 実際は、後天的にbackedge先になる点も含まれる。
          parent[child] = node; // 最後に更新された親が本物の親。
        }
      }
    } else if (visit[node] == 1) { // 子を全部巡り終えた。
      visit[node]++;
      lowest[node] = depth[node];
      for (auto child : graph_pass[node]) {
        if (child != parent[node]) {
          if (lowest[child] == -1) { // 実は子でない。つまりbackedge先の点。
            lowest[node] = min(lowest[node], depth[child]);
          } else { // これは子。子はlowest確定済み。
            // (backedgeで下がる方向は辿れるが、その先は子孫なので、
            // 子のlowestに結果には影響を及ぼさない)
            lowest[node] = min(lowest[node], lowest[child]);
          }
        }
      }
    }
  }
}

int calc_kansetsu() { // calc_lowest(); を先に実行
  fill(iskansetsu, iskansetsu+N, false);
  kansetsu_v.clear();
  // root(つまり0)は関節点か
  int root_children = 0;
  for (auto i : odd_renketsu) {
    if (parent[i] == root) {
      // cerr << "parent[" << i << "] = " << root << endl;
      root_children++;
    }
  }
  if (root_children >= 2) {
    // 子が2人以上いることが、rootが関節点であることの必要十分条件。
    // (rootは最祖先だから、backedgeを持たない)
    iskansetsu[root] = true;
  }
  // その他の辺は関節点か
  for (auto i : odd_renketsu) {
    if (parent[i] != root && parent[i] != -1
        && depth[parent[i]] <= lowest[i]) {
      // lowestで使った辺で親よりも上の階層に行けることが、
      // 親 が 関節点で な い ことの必要十分条件。
      iskansetsu[parent[i]] = true;
    }
    // 誰の親でもない点は関節点でない。
  }
  for (auto i : odd_renketsu) {
    if (iskansetsu[i]) kansetsu_v.push_back(i);
  }
  return (int)kansetsu_v.size();
}

void make_graph_tree() { // calc_lowest(); を先に実行
  for (auto i : odd_renketsu) {
    for (auto x : graph_pass[i]) {
      if (parent[x] == i) {
        graph_tree[i].push_back(x);
        graph_tree[x].push_back(i);
      }
    }
  }
}

// ここまでテンプレ

map<string, vector<int> > XYset;
set<int> settree[MAX_SIZE];
bool visited[MAX_SIZE];
bool finalans[MAX_SIZE];
int child_memo[MAX_SIZE];

int calc_child(int x) {
  if (child_memo[x] != -1) {
    return child_memo[x];
  }
  int ans = 1;
  for (auto y : graph_tree[x]) {
    if (y != parent[x]) {
      ans += calc_child(y);
    }
  }
  return child_memo[x] = ans;
}

int main() {
  cin >> N;
  N = 2 * N + 1;
  for (auto i=0; i<N; i++) {
    string x, y;
    cin >> x >> y;
    XYset[x + "x"].push_back(i);
    XYset[y + "y"].push_back(i);
  }
  for (auto x : XYset) {
    int alpha = x.second.size();
    for (auto y=0; y<alpha; y++) {
      settree[x.second[y]].insert(x.second[(y+1)%alpha]);
      settree[x.second[(y+1)%alpha]].insert(x.second[y]);
      settree[x.second[y]].insert(x.second[(y+2)%alpha]);
      settree[x.second[(y+2)%alpha]].insert(x.second[y]);
    }
  }
  for (auto i=0; i<N; i++) {
    for (auto x : settree[i]) {
      if (i != x) {
        graph_pass[i].push_back(x);
      }
    }
  }
  // 連結
  fill(visited, visited+MAX_SIZE, false);
  int troot;
  int tnow;
  int tcount = 0;
  int count_odd = 0;
  vector<int> renketsu;
  for (auto i=0; i<N; i++) {
    if (!visited[i]) {
      renketsu.clear();
      troot = i;
      tcount = 0;
      stack<int> St;
      St.push(i);
      while (!(St.empty())) {
        tnow = St.top();
        St.pop();
        if (!visited[tnow]) {
          visited[tnow] = true;
          renketsu.push_back(tnow);
          tcount++;
          for (auto x : graph_pass[tnow]) {
            if (!visited[x]) {
              St.push(x);
            }
          }
        }
      }
      if (tcount%2 == 1) {
        count_odd++;
        if (count_odd == 1) {
          copy(renketsu.begin(), renketsu.end(), back_inserter(odd_renketsu));
          root = troot;
        }
      }
    }
  }
  if (count_odd > 1) {
    // cerr << "cound_odd = " << count_odd << endl;
    for (auto i=0; i<N; i++) {
      cout << "NG" << endl;
    }
    return 0;
  }
  // 解答
  /*
  cerr << "root = " << root << endl;
  cerr << "graph_pass" << endl;
  for (auto i=0; i<N; i++) {
    cerr << "i = " << i << " : ";
    for (auto x : graph_pass[i]) {
      cerr << x << " ";
    }
    cerr << endl;
  }
  */
  fill(finalans, finalans+MAX_SIZE, false);
  calc_lowest();
  calc_kansetsu();
  make_graph_tree();
  fill(child_memo, child_memo+MAX_SIZE, -1);
  for (auto x : odd_renketsu) {
    finalans[x] = true;
  }
  /*
  cerr << "graph_tree" << endl;
  for (auto i=0; i<N; i++) {
    cerr << "i = " << i << " : ";
    for (auto x : graph_tree[i]) {
      cerr << x << " ";
    }
    cerr << endl;
  }
  for (auto x : odd_renketsu) {
    cerr << "calc_child(" << x << ") = " << calc_child(x) << endl;
  }
  */
  for (auto x : kansetsu_v) {
    // cerr << x << " is kansetsu point." << endl;
    for (auto y : graph_tree[x]) {
      if (x == parent[y] && depth[x] <= lowest[y]
          && calc_child(y)%2 == 1) {
        finalans[x] = false;
        break;
      }
    }
  }
  for (auto i=0; i<N; i++) {
    cout << (finalans[i] ? "OK" : "NG") << endl;
  }
}
