#include <iostream>
#include <algorithm>
#include <cassert>
#include <string>
using namespace std;
 
const int UFSIZE = 100010;
int union_find[UFSIZE];
int union_count[UFSIZE];
 
void init() {
  for (auto i=0; i<UFSIZE; i++) {
    union_find[i] = i;
    union_count[i] = 1;
  }
}
 
int root(int a) {
  if (a == union_find[a]) return a;
  return (union_find[a] = root(union_find[a]));
}
 
bool issame(int a, int b) {
  return root(a) == root(b);
}
 
void unite(int a, int b) {
  if (issame(a, b)) return;
  union_count[root(b)] += union_count[root(a)];
  union_find[root(a)] = root(b);  
}
 
int count(int a) {
  return union_count[root(a)];
}
 
bool isroot(int a) {
  return root(a) == a;
}
 
int N, M;
int a[100010], b[100010];
int Q;
 
struct state {
  int id;
  int x, y, z;
  int ub, lb;
  int t = 0;
  bool checked = false;
 
  state () {}
  
  state (int _id, int _x, int _y, int _z, int _ub, int _lb, int _t){
    id = _id;
    x = _x;
    y = _y;
    z = _z;
    ub = _ub;
    lb = _lb;
    t = _t;
  }
 
  string to_s() {
    string str = "";
    str += "id:" + to_string(id);
    str += ", x:" + to_string(x);
    str += ", y:" + to_string(y);
    str += ", z:" + to_string(z);
    str += ", ub:" + to_string(ub);
    str += ", lb:" + to_string(lb);
    str += ", t:" + to_string(t);
    return str;
  }
};
 
bool byt(const state& left, const state& right ) {
  return left.t < right.t;
}
 
bool byid(const state& left, const state& right ) {
  return left.id < right.id;
}
 
state V[100010];
 
int main() {
  cin >> N >> M;
  for (auto i = 0; i < M; i++) {
    cin >> a[i] >> b[i];
    a[i]--; b[i]--;
  }
  cin >> Q;
  for (auto i = 0; i < Q; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    x--; y--;
    state temp(i, x, y, z, M, 0, M/2);
    V[i] = temp;
    //cerr << temp.to_s() << endl;
  }
  int ccount = 0;
  while (ccount < Q) {
    init();
    sort(V, V+Q, byt);
    int ind = 0;
    int indq = 0;
    while (indq < Q) {
      if (V[indq].t > ind) {
        unite(a[ind], b[ind]);
        ind++;
      } else {
        // cerr << V[indq].to_s() << endl;
        assert(V[indq].t == ind);
        if (V[indq].checked) {
          indq++;
          continue;
        }
        int cnt;
        if (issame(V[indq].x, V[indq].y)) {
          cnt = count(V[indq].x);
        } else {
          cnt = count(V[indq].x) + count(V[indq].y);
        }
        if (cnt >= V[indq].z) {
          V[indq].ub = V[indq].t;          
        } else {
          V[indq].lb = V[indq].t;
        }
        // cerr << "cnt: " << cnt << ", ind: " << ind << endl;
        if (V[indq].ub - V[indq].lb == 1) {
          V[indq].checked = true;
          ccount++;
        } else {
          V[indq].t = (V[indq].ub + V[indq].lb)/2;
          indq++;
        }
      }
    }
  }
  sort(V, V+Q, byid);
  for (auto i = 0; i < Q; i++) {
    cout << V[i].ub << endl;
  }
}
