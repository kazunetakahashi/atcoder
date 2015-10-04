#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

typedef tuple<int, bool> rabbit;

struct state {
  int dist = 0;
  vector<int> R;
  vector<int> L;
};

int main() {
  int N, Len;
  cin >> N >> Len;
  vector<rabbit> V;
  int tempi;
  char tempc;
  bool tempb;
  for (auto i=0; i<N; i++) {
    cin >> tempi >> tempc;
    tempb = (tempc == 'R');
    V.push_back(make_tuple(tempi-1, tempb));
  }
  long long ans = 0;
  auto it = V.begin();
  while (it != V.end()) {
    state S;
    bool isR = true;
    while (it != V.end()) {
      if (isR && get<1>(*it)) {
        S.R.push_back(get<0>(*it++));
      } else if ((!isR) && get<1>(*it)) {
        break;
      } else {
        isR = false;
        S.L.push_back(get<0>(*it++));
      }
    }
    if (S.R.empty()) {
      S.R.push_back(-1);
    } else if (S.L.empty()) {
      S.L.push_back(Len);
    }
    reverse(S.R.begin(), S.R.end());
    for (unsigned i=0; i<S.R.size(); i++) {
      ans += S.R[0] - S.R[i] - i; 
    }
    for (unsigned i=0; i<S.L.size(); i++) {
      ans += S.L[i] - S.L[0] - i; 
    }
    long long big = (long long)max(S.R.size(), S.L.size());
    S.dist = S.L[0] - S.R[0] - 1;
    ans += S.dist * big;
  }
  cout << ans << endl;
}
