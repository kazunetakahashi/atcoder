#include <iostream>
#include <tuple>
#include <string>
#include <algorithm>
#include <stack>
#include <iterator>
using namespace std;

typedef tuple<int, int> point;

int N;
bool F[410][410];
point s;
int sum = 0;
bool isodd[2][410];

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

bool valid(int x, int y) {
  return (0 <= x && x < N && 0 <= y && y < N && F[x][y]);
}

int main() {
  cin >> N;
  string S;
  fill(&isodd[0][0], &isodd[0][0]+2*410, false);
  for (auto i=0; i<N; i++) {
    cin >> S;
    for (auto j=0; j<N; j++) {
      F[i][j] = (S[j] != '#');
      if (F[i][j]) {
        sum++;
        isodd[0][i] = !isodd[0][i];
        isodd[1][j] = !isodd[1][j];
      }
      if (S[j] == 's') {
        s = make_tuple(i, j);
      }
    }
  }
  /*
  for (auto j=0; j<2; j++) {
    for (auto k=0; k<N; k++) {
      if (isodd[j][k]) {
        cerr << "kiroku j = " << j << ", k = " << k << endl;
      }
    }
  }
  cerr << " == " << endl;
  */
  bool ans = false;
  bool startcan[2];
  for (auto i=0; i<4; i++) {
    if (valid(get<0>(s)+dx[i], get<1>(s)+dy[i])) {
      startcan[i/2] = true;
    }
  }
  for (auto i=0; i<2; i++) {
    if (!startcan[i]) {
      // cerr << "cannot start " << i << endl;
      continue;
    }
    bool isscol = (i == 0);
    if (!isscol) {
      isodd[1][get<1>(s)] = !isodd[1][get<1>(s)];
    } else {
      isodd[0][get<0>(s)] = !isodd[0][get<0>(s)];
    }
    int oddcount = 0;
    int kirokuj, kirokuk;
    for (auto j=0; j<2; j++) {
      for (auto k=0; k<N; k++) {
        if (isodd[j][k]) {
          // cerr << "kiroku j = " << j << ", k = " << k << endl;
          oddcount++;
          kirokuj = j;
          kirokuk = k;
        }
      }
    }
    if (!isscol) {
      isodd[1][get<1>(s)] = !isodd[1][get<1>(s)];
    } else {
      isodd[0][get<0>(s)] = !isodd[0][get<0>(s)];
    }
    if (oddcount != 1) {
      continue;
    }
    /*
    cerr << "start = " << i << ", kirokuj = "
         << kirokuj << ", kirokuk = " << kirokuk << endl;
    */
    bool drawn = true;
    vector<point> W[410][410];
    for (auto k=0; k<2; k++) {
      if (isscol == (k == 0)) {
        F[get<0>(s)][get<1>(s)] = false; 
      }
      for (auto l=0; l<N; l++) {
        if ((k == kirokuj) && (l == kirokuk)) continue;
        for (auto m=0; m<N; m++) {
          if (k == 0 && F[l][m]) {
            if (valid(l, m+1)) {
              W[l][m].push_back(make_tuple(l, m+1));
              W[l][m+1].push_back(make_tuple(l, m));
              m++;
            } else {
              //cerr << "connecting (" << l << ", " << m << ") and "
              //     << "(" << l << ", " << m+1 << ") fails." << endl;
              drawn = false;
              goto EXIT;
            }
          } else if (k == 1 && F[m][l]) {
            if (valid(m+1, l)) {
              W[m][l].push_back(make_tuple(m+1, l));
              W[m+1][l].push_back(make_tuple(m, l));
              m++;
            } else {
              //cerr << "connecting (" << m << ", " << l << ") and "
              //     << "(" << m+1 << ", " << l << ") fails." << endl;
              drawn = false;
              goto EXIT;
            }
          }
        }
      }
    EXIT:
      if (isscol == (k == 0)) {
        F[get<0>(s)][get<1>(s)] = true; 
      }
    }
    if (!drawn) continue;
    bool isgcol = (kirokuj == 0);
    for (auto j=0; j<N; j++) {
      drawn = true;
      point g = ((!isgcol) ? make_tuple(j, kirokuk) : make_tuple(kirokuk, j));
      if (s == g) continue;
      if (!valid(get<0>(g), get<1>(g))) continue;
      // cerr << "g = (" << get<0>(g) << ", " << get<1>(g) << ")" << endl;
      if (isscol == (kirokuj == 0)) {
        F[get<0>(s)][get<1>(s)] = false; 
      }
      F[get<0>(g)][get<1>(g)] = false;
      for (auto m=0; m<N; m++) {
        if (kirokuj == 0 && F[kirokuk][m]) {
          if (valid(kirokuk, m+1)) {
            m++;
          } else {
            //cerr << "connecting (" << kirokuk << ", " << m << ") and "
            //     << "(" << kirokuk << ", " << m+1 << ") fails." << endl;
            drawn = false;
            goto EXIT3;
          }
        } else if (kirokuj == 1 && F[m][kirokuk]) {
          if (valid(m+1, kirokuk)) {
            m++;
          } else {
            //cerr << "connecting (" << m << ", " << kirokuk << ") and "
            //     << "(" << m+1 << ", " << kirokuk << ") fails." << endl;
            drawn = false;
            goto EXIT3;
          }
        }
      }
      for (auto m=0; m<N; m++) {
        if (kirokuj == 0 && F[kirokuk][m]) {
          W[kirokuk][m].push_back(make_tuple(kirokuk, m+1));
          W[kirokuk][m+1].push_back(make_tuple(kirokuk, m));
          m++;
        } else if (kirokuj == 1 && F[m][kirokuk]) {
          W[m][kirokuk].push_back(make_tuple(m+1, kirokuk));
          W[m+1][kirokuk].push_back(make_tuple(m, kirokuk));
          m++;
        }
      }
    EXIT3:
      if (isscol == (kirokuj == 0)) {
        F[get<0>(s)][get<1>(s)] = true; 
      }
      F[get<0>(g)][get<1>(g)] = true;
      if (!drawn) continue;
      /*
      cerr << "size of W[k][l] : " << endl;
      for (auto k=0; k<N; k++) {
        for (auto l=0; l<N; l++) {
          cerr << W[k][l].size();
        }
        cerr << endl;
      }
      */
      int cnt = 0;
      point now = s;
      point prev;
      while (now != g) {
        cnt++;
        if (now == s) {
          prev = s;
          now = W[get<0>(now)][get<1>(now)][0];
        } else {
          for (auto e:W[get<0>(now)][get<1>(now)]) {
            if (prev != e) {
              prev = now;
              now = e;
              break;
            }
          }
        }
      }
      // cerr << "cnt = " << cnt << endl;
      if (cnt+1 == sum) {
        ans = true;
        goto EXIT2;
      }
      for (auto m=0; m<N; m++) {
        if (kirokuj == 0 && F[kirokuk][m]) {
          W[kirokuk][m].erase(W[kirokuk][m].end()-1);
          W[kirokuk][m+1].erase(W[kirokuk][m+1].end()-1);
          m++;
        } else if (kirokuj == 1 && F[m][kirokuk]) {
          W[m][kirokuk].erase(W[m][kirokuk].end()-1);
          W[m+1][kirokuk].erase(W[m+1][kirokuk].end()-1);
          m++;
        }
      }
    }
  }
 EXIT2:
  cout << (ans ? "POSSIBLE" : "IMPOSSIBLE") << endl;
}
