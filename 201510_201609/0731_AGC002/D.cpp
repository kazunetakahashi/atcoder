#include <iostream>
#include <algorithm>
#include <vector>
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
 
vector<state> V;
 
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
    V.push_back(temp);
    //cerr << temp.to_s() << endl;
  }
  int ccount = 0;
  while (ccount < Q) {
    init();
    sort(V.begin(), V.end(), byt);
    int ind = 0;
    auto it = V.begin();
    while (it != V.end()) {
      if ((*it).t > ind) {
        unite(a[ind], b[ind]);
        ind++;
      } else {
        // cerr << (*it).to_s() << endl;
        assert((*it).t == ind);
        if ((*it).checked) {
          it++;
          continue;
        }
        int cnt;
        if (issame((*it).x, (*it).y)) {
          cnt = count((*it).x);
        } else {
          cnt = count((*it).x) + count((*it).y);
        }
        if (cnt >= (*it).z) {
          (*it).ub = (*it).t;          
        } else {
          (*it).lb = (*it).t;
        }
        // cerr << "cnt: " << cnt << ", ind: " << ind << endl;
        if ((*it).ub - (*it).lb == 1) {
          (*it).checked = true;
          ccount++;
        } else {
          (*it).t = ((*it).ub + (*it).lb)/2;
          it++;
        }
      }
    }
  }
  sort(V.begin(), V.end(), byid);
  for (auto tmp : V) {
    cout << tmp.ub << endl;
  }
}
