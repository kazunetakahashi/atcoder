#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <set>
using namespace std;

int H, W;

struct stage {
  int zero;
  vector<int> a = vector<int>(36);

  bool operator<( const stage& right ) const {
    if (zero != right.zero) return (zero < right.zero);
    for (auto i=0; i<H*W; i++) {
      if (a[i] != right.a[i]) return (a[i] < right.a[i]);
    }
    return false;
  }
  bool operator>( const stage& right ) const {
    if (zero != right.zero) return (zero > right.zero);
    for (auto i=0; i<H*W; i++) {
      if (a[i] != right.a[i]) return (a[i] > right.a[i]);
    }
    return false;
  }
  bool operator==( const stage& right ) const {
    if (zero != right.zero) return false;
    for (auto i=0; i<H*W; i++) {
      if (a[i] != right.a[i]) return false;
    }
    return true;
  }
};

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
const int M = 12;
vector< set< stage > > start;
vector< set< stage > > goal;

int zahyo(int i, int j) {
  return i * W + j;
}

int alpha(int i) {
  return i/W;
}

int beta(int i) {
  return i%W;
}

bool isvalid(int i, int j) {
  return (0 <= i && i < H && 0 <= j && j < W);
}

stage copy(stage Y) {
  stage X;
  X.zero = Y.zero;
  for (auto i=0; i<H*W; i++) {
    X.a[i] = Y.a[i];
  }
  return X;
}

int main() {
  cin >> H >> W;
  // 初期状態
  stage ini;
  for (auto i=0; i<H*W; i++) {
    cin >> ini.a[i];
    if (ini.a[i] == 0) {
      ini.zero = i;
    }
  }
  set< stage > tv;
  tv.insert(ini);
  start.push_back(tv);
  // 最終状態
  stage fin;
  for (auto i=0; i<H*W; i++) {
    fin.a[i] = (i+1)%(H*W);
    if (fin.a[i] == 0) {
      fin.zero = i;
    }
  }
  set< stage > tv2;
  tv2.insert(fin);
  goal.push_back(tv2);
  if (ini == fin) {
    cout << 0 << endl;
    return 0;
  }
  // 初期状態からM回変形
  for (auto t=1; t<=M; t++) {
    set<stage> temp;
    start.push_back(temp);
    for (auto i=start[t-1].begin(); i != start[t-1].end(); i++) {
      /* if (t < 3) {
        cerr << "pattrn" << endl;
        for (auto j=0; j<H*W; j++) {
          cerr << (*i).a[j] << " ";
          if (beta(j) == W-1) cerr << endl;
        }
        } */
      int n = (*i).zero;
      int x = alpha(n);
      int y = beta(n);
      for (auto j=0; j<4; j++) {
        int nx = x+dx[j];
        int ny = y+dy[j];
        int nn = zahyo(nx, ny);
        if (isvalid(nx, ny)) {
          stage next = copy(*i);
          swap(next.a[n], next.a[nn]);
          next.zero = nn;
          start[t].insert(next);
        }
      }
    }
    // cerr << "t = " << t << ", size = " << start[t].size() << endl;
    if (start[t].find(fin) != start[t].end()) {
      cout << t << endl;
      return 0;
    }
  }
  // start[M]をvectorになおす。
  vector<stage> afterM;
  for (auto i = start[M].begin(); i != start[M].end(); i++) {
    afterM.push_back(*i);
  }
  sort(afterM.begin(), afterM.end());
  // 最終状態からM回変形
  for (auto t=1; t<=M; t++) {
    set<stage> temp;
    goal.push_back(temp);
    for (auto i=goal[t-1].begin(); i != goal[t-1].end(); i++) {
      /* if (t < 3) {
        cerr << "pattrn" << endl;
        for (auto j=0; j<H*W; j++) {
          cerr << (*i).a[j] << " ";
          if (beta(j) == W-1) cerr << endl;
        }
        } */
      int n = (*i).zero;
      int x = alpha(n);
      int y = beta(n);
      for (auto j=0; j<4; j++) {
        int nx = x+dx[j];
        int ny = y+dy[j];
        int nn = zahyo(nx, ny);
        if (isvalid(nx, ny)) {
          stage next = copy(*i);
          swap(next.a[n], next.a[nn]);
          next.zero = nn;
          goal[t].insert(next);
        }
      }
    }
    // cerr << "t = " << t << ", size = " << start[t].size() << endl;
    // vectorになおす。
    vector<stage> beforet;
    for (auto i = goal[t].begin(); i != goal[t].end(); i++) {
      beforet.push_back(*i);
    }
    sort(beforet.begin(), beforet.end());
    unsigned int a=0, b=0;
    while (a < afterM.size() && b < beforet.size()) {
      if (afterM[a] < beforet[b]) a++;
      else if (afterM[a] > beforet[b]) b++;
      else {
        cout << M + t << endl;
        return 0;
      }
    }
  }
}
