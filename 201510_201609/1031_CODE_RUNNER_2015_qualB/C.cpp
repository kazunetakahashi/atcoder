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
ll nokori = -1;
vector<ll> enemy;
double rate = 0.4;
double prev_rate;
ll mokuhyo_score;
ll kogeki_kaisu = 0;
double RATE = 0.4;
ll aite_sum[2];
ll all_sum;
ll prev_t;
ll kijun = 0;

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
  prev_t = nokori;
  ss >> now_power >> now_sum;  
  ss >> enemy_hp >> enemy_hp_i;
  ss >> nokori;
  cout << "info: " << endl;
  cout << now_power << " " << now_sum << endl;  
  cout << enemy_hp << " " << enemy_hp_i << endl;
  cout << nokori << endl;
  enemy.clear();
  for (auto i=0; i<nokori; i++) {
    ll x;
    ss >> x;
    cout << x << endl;
    enemy.push_back(x);
  }
  string ste;
  ss >> ste >> ste >> aite_sum[0];
  ss >> ste >> ste >> aite_sum[1];
  cout << "aite: " << aite_sum[0] << " " << aite_sum[1] << endl;
  sort(aite_sum, aite_sum+2);
  reverse(aite_sum, aite_sum+2);
  all_sum = aite_sum[0] + aite_sum[1] + now_sum;
  cout << "-----" << endl;
  if (prev_t < nokori) {
    kogeki_kaisu = 0;
    rate = RATE;
    sort(enemy.begin(), enemy.end());
    reverse(enemy.begin(), enemy.end());
    kijun = enemy[enemy.size()/2];
  } else {
    prev_rate = rate;
    if (aite_sum[0] <= now_sum) {
    } else {
      double new_rate = (double)aite_sum[0]/all_sum;
      double jibun_rate = (double)now_sum/all_sum;
      rate = (new_rate+jibun_rate)/2;
    }
  }
  cout << "rate = " << fixed << setprecision(5) << rate << endl;
  kogeki_kaisu++;  
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
 EXIT:
  init();
  while (true) {
  EXIT2:
    double wait_t;
    getinfo();
    if (now_power == 0) {
      prev_t = -1;
      goto EXIT;
    } else if (enemy_hp < kijun/2) {
      sleep_m(0.2);
      goto EXIT2;
    }
    ll kouryohp = enemy_hp;
    if (!enemy.empty()) {
      kouryohp = max(500.0 * 500.0, min(enemy_hp * rate, enemy[0] * rate));
    }
    wait_t = sqrt(kouryohp)/1000;
    wait_t -= sqrt(now_power)/1000;
    sleep_m(max(0.0, wait_t));
    attack();
    if (result[0] == 'G') {
      sleep_m(1);
      cout << "myrank" << endl;
      cout << getmyrank() << endl;
      cout << "-----" << endl;
      prev_t = -1;
    } else if (result[0] == 'E') {
      cout << result << endl;
      sleep_m(0.5);
      init();
    } else {
      cout << result << endl;
    }
  }
}
