#include <iostream>
#include <algorithm>
#include <vector>
// #include <tuple>
#include <cassert>
using namespace std;

// typedef tuple<int, int> point;
const int C = 1048586;

typedef long long ll;

const int M = 1000000007;

const int dx[2][2] = { {-5, 5}, {-1, 1} };

ll DP[C];
int x[25]; // 場本体
bool used[25]; // used[num] = numが使われているか否か
bool field[25]; // field[zahyo] = zahyoが空欄であるか否か
int X[25]; // xの逆
vector<int> remnum;
vector<int> remzahyo;

bool sft(int table, int c) {
  return (((table >> c) & 1) == 1);
}

bool checker(int state, int ini_p, int ini_num) {
  // bool debug = (ini_num == 5);
  for (int num=ini_num; num<25; num++) {
    if (num > ini_num && (!used[num])) return true;
    // if (debug) cerr << "num = " << num << endl;
    int p = ((num == ini_num) ? ini_p : X[num]);
    int table = 0;
    for (auto i=0; i<25; i++) {
      if (x[i] != -1 && x[i] <= num) {
        table += (1 << i);
      }
      if (sft(state, i)) {
        table += (1 << remzahyo[i]);
      }
    }
    /*
    if (debug) {
      for (auto i=0; i<25; i++) {
        if (i == p) {
          cerr << "!";
        } else if (sft(table, i)) {
          cerr << "o";
        } else {
          cerr << "x";
        }
        if (i%5 == 4) cerr << endl;
      }
    }
    */
    bool ok = true;
    int pp[2] = {p/5, p%5};
    for (auto i=0; (i<2) && ok; i++) {
      if ((pp[i] == 0) || (pp[i] == 4)) continue;
      int q = p+dx[i][0];
      int r = p+dx[i][1];
      bool qb = sft(table, q);
      bool rb = sft(table, r);
      ok = ((qb && rb) || (!qb && !rb));
    }
    if (!ok) {
      // if (debug) cerr << "BAD" << endl;
      return false;
    }
  }
  return true;
}

int main() {
  fill(used, used+25, false);
  fill(field, field+25, true);
  for (auto i=0; i<5; i++) {
    for (auto j=0; j<5; j++) {
      int t = i * 5 + j;
      cin >> x[t];
      x[t]--;
      if (x[t] == -1) {
        remzahyo.push_back(t);
      } else {
        used[x[t]] = true;
        field[t] = false;
        X[x[t]] = t;
      }
    }
  }
  for (auto i=0; i<25; i++) {
    if (!used[i]) {
      remnum.push_back(i);
    }
  }
  assert(remnum.size() == remzahyo.size());
  int size = (int)(remnum.size());
  /*
  cerr << "remnum : ";
  for (auto i=0; i<size; i++) {
    cerr << remnum[i] << " ";
  }
  cerr << endl;
  cerr << "remzahyo : ";
  for (auto i=0; i<size; i++) {
    cerr << remzahyo[i] << " ";
  }
  cerr << endl;
  */
  fill(DP, DP+C, 0);
  DP[0] = 1;
  if (!(checker(0, X[0], 0))) {
    cout << 0 << endl;
    return 0;
  }
  for (auto cnt=1; cnt<=size; cnt++) {
    int i = (1 << cnt) - 1;
    while (i < (1 << size)) {
      int num = remnum[cnt-1]; // これから入れる数字
      for (auto j=0; j<size; j++) {
        int blza = remzahyo[j]; // これから入れたい場所
        if (sft(i, j) && checker(i, blza, num)) {
          DP[i] += DP[i - (1 << j)];
          DP[i] %= M;
        }
      }
      /*
      if (DP[i] != 0) {
        cerr << "inserting : " << num << endl;
        cerr << "DP = " << DP[i] << endl;
        int temp_field[25];
        for (auto j=0; j<25; j++) {
          temp_field[j] = x[j];
        }
        for (auto j=0; j<size; j++) {
          if (sft(i, j)) {
            int temp_z = remzahyo[j];
            temp_field[temp_z] = -2;
          }
        }
        for (auto j=0; j<25; j++) {
          if (temp_field[j] >= 0) {
            cerr << temp_field[j] << " ";
          } else if (temp_field[j] == -2) {
            cerr << "o ";
          } else {
            cerr << "x ";
          }
          if (j%5 == 4) {
            cerr << endl;
          }
        }
      }
      */
      // 処理
      int temp1 = i & (-i);
      int temp2 = i + temp1;
      int temp3 = i & (~temp2);
      i = (((temp3/temp1) >> 1) | temp2);
    }
  }
  cout << DP[(1 << size)-1] << endl;
}
