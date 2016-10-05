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
string token = "4ABBE2VFR2LMM0CBQ2C4YZZUJSVJ5YK2";
string url;
string result;

ll now_power, now_sum;
ll enemy_hp, enemy_hp_i;
ll nokori;
vector<ll> enemy;

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

string attack() {
  url = "https://game.coderunner.jp/enter?token=" + token;
  result = query(url);
  return result;
}

stringstream getinfo() {
  url = "https://game.coderunner.jp/info?token=" + token;
  result = query(url);
  stringstream ss(result);
  ss >> now_power >> now_sum;  
  ss >> enemy_hp >> enemy_hp_i;
  ss >> nokori;
  cout << "info: " << endl;
  cout << now_power << " " << now_sum << endl;  
  cout << enemy_hp << " " << enemy_hp_i << endl;
  cout << nokori;
  enemy.clear();
  for (auto i=0; i<nokori; i++) {
    ll x;
    ss >> x;
    cout << x << endl;
    enemy.push_back(x);
  }
  cout << "-----" << endl;
  return ss;
}

string getmyrank() {
  url = "https://game.coderunner.jp/myrank?token=" + token;
  result = query(url);
  return result;
}

void init() {
  while (true) {
    attack();
    if (result[0] != 'E') {
      cout << result << endl;
      break;
    } else {
      sleep_m(0.5);
    }
  }
}

int main() {
  init();
  while (true) {
    double wait_t = 0.2;
    sleep_m(wait_t);
    getinfo();
    ll kouryohp = enemy_hp;
    if (!enemy.empty()) {
      kouryohp = max(enemy_hp, enemy[0]);
    }
    wait_t = sqrt(kouryohp/3)/1000;
    wait_t -= sqrt(now_power)/1000;
    sleep_m(max(wait_t, 0.5));
    attack();
    if (result[0] == 'G') {
      sleep_m(1);
      cout << "myrank" << endl;
      cout << getmyrank() << endl;
      cout << "-----" << endl;
    } else if (result[0] == 'E') {
      cout << result << endl;
      sleep_m(0.5);
      init();
    } else {
      cout << result << endl;
    }
  }
}
