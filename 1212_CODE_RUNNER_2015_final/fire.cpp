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
};
vector<work> W;
int outer;
vector<work> O;

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
  for (auto i = 0; i < have; i++) {
    work temp;
    ss >> temp.id >> temp.t >> temp.amount
       >> temp.kind >> temp.income >> temp.loss;
    O.push_back(temp);
  }
}

int main() {
  while (true) {
    getinfo();
    vector<int> V;
    for (auto i = 0; i < 50; i++) {
      cout << "No. " << i << " : ";
      for (auto j = 0; j < 50; j++) {
        cout << speed[i][j];
      }
      cout << endl;
    }
    for (auto i = 0; i < 50; i++) {
      int maxi = 0;
      for (auto j = 0; j < 50; j++) {
        maxi = max(maxi, speed[i][j]);
      }
      if (maxi < 9) {
        V.push_back(i);
      }
    }
    if (V.empty()) return 0;
    cout << "Fire : ";
    for (auto x : V) {
      cout << x << " ";
    }
    url = "http://game.coderunner.jp/change?worker=";
    for (unsigned i = 0; i < V.size(); i++) {
      url += to_string(V[i]);
      if (i < V.size()-1) url += ",";
    }
    url += "&token=" + token;
    result = query(url);
    cout << "Changed: ";
    cout << result << endl;
    double wait_t = 30;    
    sleep_m(wait_t);
  }
}
