#include <string>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <algorithm>
#include <random>
#include <vector>
#include <iomanip>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <tuple>
#include <sstream>

using namespace std;

typedef long long ll;

random_device rd;
mt19937 mt(rd());
string token = "D4F13LXWMKE22ONMJYGYZT1TE8ZVAZKM";
string url;
string result;



void sleep_m(double x) {
  usleep((ll)floor(x*1000000));
}

string query(string url) {
  FILE *f = popen(("curl -s -k \"" + url + "\"").c_str(), "r");
  if (f == NULL) {
    perror("error!");
  }
  char buf[1024];
  string res;
  while (!feof(f)) {
    if (fgets(buf, 1024, f) == NULL) break;
    res += (string)(buf);
  }
  pclose(f);
  return res;
}

ll money;
int speed[50][50];
int waiting[50];
int keikenchi[50];
int have;
struct work {
  int id;
  int t;
  int amount;
  int kind;
  int income;
  int loss;
  bool operator<(const work &right) const {
    return ((double)income)/amount < ((double)right.income)/right.amount;
  }
};
vector<work> W;
int outer;
vector<work> O;
vector<int> tokui[50];

void getinfo() {
  url = "http://game.coderunner.jp/getinfo?token=" + token;
  result = query(url);
  stringstream ss(result);
  ss >> money;
  int t;
  ss >> t >> t;
  for (auto i = 0; i < 50; i++) {
    ss >> t;
    for (auto j = 0; j < 50; j++) {
      ss >> speed[i][j];
    }
    ss >> waiting[i];
    ss >> keikenchi[i];
  }
  ss >> have;
  W.clear();
  for (auto i = 0; i < have; i++) {
    work temp;
    ss >> temp.id >> temp.t >> temp.amount >> temp.kind
       >> temp.income >> temp.loss;
    W.push_back(temp);
  }
  ss >> outer;
  O.clear();
  for (auto i = 0; i < outer; i++) {
    work temp;
    ss >> temp.id >> temp.t >> temp.amount
       >> temp.kind >> temp.income >> temp.loss;
    O.push_back(temp);
  }
  bool visited[50];
  fill(visited, visited+50, false);
  int maximum[50];
  fill(maximum, maximum+50, 0);
  for (auto i = 0; i < 50; i++) {
    for (auto j = 0; j < 50; j++) {
      maximum[i] = max(maximum[i], speed[i][j]);
    }
  }
  for (auto i = 0; i < 50; i++) {
    tokui[i].clear();
  }

  for (auto i = 0; i < 50; i++) {
    for (auto j = 0; j < 50; j++) {
      if ((speed[i][j] == maximum[i]) && (tokui[j].empty())) {
        tokui[j].push_back(i);
        visited[i] = true;
        break;
      }
    }
  }
  for (auto i = 0; i < 50; i++) {
    if (visited[i]) continue;
    for (auto j = 0; j < 50; j++) {
      if (speed[i][j] == maximum[i]) {
        tokui[j].push_back(i);
        break;
      }
    }
  }
}

int getoutnum;
vector<work> X;

void getout() {
  url = "http://game.coderunner.jp/getout?token=" + token;
  result = query(url);
  stringstream ss(result);
  ss >> getoutnum;
  X.clear();
  for (auto i = 0; i < getoutnum; i++) {
    work temp;
    ss >> temp.id >> temp.t >> temp.amount >> temp.kind
       >> temp.income;
    temp.loss = 0;
    X.push_back(temp);
  }
}

void outside() {
  sort(X.begin(), X.end());
  reverse(X.begin(), X.end());
  for (auto x : X) {
    int wpower = 0;
    vector<int> ugokeru;
    for (auto y : tokui[x.kind]) {
      if (waiting[y] == 0) {
        wpower += speed[y][x.kind];
        ugokeru.push_back(y);
      }
    }
    cerr << wpower << " " << x.t << " " << x.amount << endl;
    if (wpower * x.t > x.amount
        && x.income * 100 > 125 * (x.amount/wpower)) {
      url = "http://game.coderunner.jp/assign?task="
        + to_string(x.id) + "&worker=";
      for (unsigned y = 0; y < ugokeru.size(); y++) {
        url += to_string(ugokeru[y]);
        if (y != ugokeru.size()-1) url += ",";
      }
      url += "&token=" + token;
      cerr << url << endl;
      result = query(url);
      cerr << "result : " << result << endl;
      if (result == "OK") {
        cout << "assigned: ";
        for (auto y : ugokeru) {
          cout << y << " ";
        }
        cout << endl;
        cout << "time: " << x.amount/wpower << ", income: " << x.income << endl;
        return;
      }
    }
  }
}

int main() {
  while (true) {
    getout();
    getinfo();
    outside();
    sleep_m(1);
  }
}
