#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <tuple>
#include <stack>
#include <queue>
#include <string>
#include <set>
#include <map>
using namespace std;

typedef tuple<int, int, int> route;
typedef tuple<int, int, int> people;
typedef tuple<int, int> ans;

const int UFSIZE = 100010;
int union_find[UFSIZE];
int num[UFSIZE];

void init() {
  for (auto i=0; i<UFSIZE; i++) {
    union_find[i] = i;
  }
  fill(num, num+UFSIZE, 1);
}

int root(int a) {
  if (a == union_find[a]) return a;
  return (union_find[a] = root(union_find[a]));
}

int number(int a) {
  return num[root(a)];
}

bool issame(int a, int b) {
  return root(a) == root(b);
}

void unite(int a, int b) {
  if (root(a) != root(b)) {
    num[root(b)] += num[root(a)];
    union_find[root(a)] = root(b);
  }
}

bool isroot(int a) {
  return root(a) == a;
}

vector<route> R;
vector<people> P;
vector<ans> A;

int main() {
  init();
  int N, M;
  cin >> N >> M;
  int a, b, y;
  for (auto i = 0; i < M; i++) {
    cin >> a >> b >> y;
    a--; b--;
    R.push_back(make_tuple(y, a, b));
  }
  int Q;
  cin >> Q;
  int v, w;
  for (auto i = 0; i < Q; i++) {
    cin >> v >> w;
    v--;
    P.push_back(make_tuple(w, v, i));
  }
  sort(R.begin(), R.end());
  reverse(R.begin(), R.end());
  sort(P.begin(), P.end());
  reverse(P.begin(), P.end());
  auto ir = R.begin();
  auto ip = P.begin();
  while (ip != P.end()) {
    w = get<0>(*ip);
    v = get<1>(*ip);
    int id = get<2>(*ip);
    while (ir != R.end() && get<0>(*ir) > w) {
      unite(get<1>(*ir), get<2>(*ir));      
      ir++;
    }
    A.push_back(make_tuple(id, number(v)));
    ip++;
  }
  sort(A.begin(), A.end());
  for (auto x : A) {
    cout << get<1>(x) << endl;
  }
}
