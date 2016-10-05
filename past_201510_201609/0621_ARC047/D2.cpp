#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

const int M = 5005;
const int infty = 1e9;

int ary[2][10010];
int sum[2][10010];

void query_1(int A, int B, int C) {
  ary[0][A] += C;
  ary[0][B+1] -= C;
}

void query_2(int A, int B, int C) {
  ary[1][A+M] += C;
  ary[1][B+1+M] -= C;
}

void query_3(int A, int B, int C, int D) {
  for (auto i = 0; i < 2; i++) {
    for (auto j = 0; j < 10010; j++) {
      sum[i][j] = ary[i][j];
      /*
      if (sum[i][j] != 0) {
        cerr << "sum[" << i << "][" << j << "] = " << sum[i][j] << endl;
      }
      */
    }
  }
  for (auto i = 0; i < 2; i++) {
    for (auto j = 1; j < 10010; j++) {
      sum[i][j] += sum[i][j-1];
      /*
      if (sum[i][j] != 0) {
        cerr << "sum[" << i << "][" << j << "] = " << sum[i][j] << endl;
      }
      */
    }
  }
  int ans_maxi = -infty;
  int ans_cnt = 0;
  for (auto k = 0; k < 2; k++) {
    int ps = A-C;
    int pg = A-C;
    multiset<int> S;
    for (auto i = A+C; i <= B+D; i++) {
      // cerr << "i = " << i << endl;
      if (i%2 != k) continue;
      int s = ((i-A < D) ? (2*A-i) : (i-2*D));
      int g = ((i-C < B) ? (i-2*C) : (2*B-i));
      // cerr << "s = " << s << ", g = " << g << endl;
      if (i == A+C) {
        S.insert(sum[1][s+M]);
      } else if (i == A+C+1) {
        S.insert(sum[1][s+M]);
        if (s != g) S.insert(sum[1][g+M]);
      } else {
        if (ps < s) {
          S.erase(S.find(sum[1][ps+M]));
        } else if (ps > s) {
          S.insert(sum[1][s+M]);      
        }
        if (pg < g) {
          S.insert(sum[1][g+M]);
        } else if (pg > g) {
          S.erase(S.find(sum[1][pg+M]));      
        }
      }
      /*
      cerr << "S : ";
      for (auto x : S) {
        cerr << x << " ";
      }
      cerr << endl;
      */
      ps = s;
      pg = g;
      auto it = S.end();
      it--;
      int maxi = *it;
      int cnt = S.count(maxi);
      int t = sum[0][i] + maxi;
      // cerr << "t = " << sum[0][i] << " + " << maxi << endl;
      if (ans_maxi < t) {
        ans_maxi = t;
        ans_cnt = cnt;
      } else if (ans_maxi == t) {
        ans_cnt += cnt;
      }
    }
  }
  cout << ans_maxi << " " << ans_cnt << endl;
}

int main() {
  int N, Q;
  cin >> N >> Q;
  fill(&ary[0][0], &ary[0][0]+2*10010, 0);
  fill(&sum[0][0], &sum[0][0]+2*10010, 0);
  int q, A, B, C, D;
  for (auto i = 0; i < Q; i++) {
    cin >> q;
    if (q == 1) {
      cin >> A >> B >> C;
      query_1(A, B, C);
    } else if (q == 2) {
      cin >> A >> B >> C;
      query_2(A, B, C);
    } else {
      cin >> A >> B >> C >> D;
      query_3(A, B, C, D);
    }
  }
}
