#include <string>
#include <random>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <typeinfo>
#include <tuple>

#ifdef _MSC_VER
#include <Windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

string token  = "CDDWWCMTEL9DCK15I5VST8FRIZRJSSSC";

int s_d[5] = {500, 250, 125, 50, 0};
int s_u[5] = {1000, 500, 250, 125, 50};

int prev_score[5];

random_device rd;
mt19937 mt(rd());

typedef tuple<int, int, vector<int> > monster; // score, id, need
monster M[1010];

int have[25];
int koukan[25][25];

int make_random (int mod) {
  return mt()%mod;
}

string query(string url) {
  
#ifdef _MSC_VER
  FILE *f = _popen(("C:\\bin\\curl.exe -s -k \"" + url + "\"").c_str(), "r");
#else
  FILE *f = popen(("curl -s -k \"" + url + "\"").c_str(), "r");
#endif
  
  if (f == NULL) {
    perror("error!");
  }
  char buf[1024];
  string res;

  while (!feof(f)) {
    if (fgets(buf, 1024, f) == NULL) break;
    res += (string)(buf);
  }
  
#ifdef _MSC_VER
  _pclose(f);
#else
  pclose(f);
#endif

  return res;
}

void init_monster() {
  ifstream fin("monsters.txt");
  for (auto i=0; i<1000; i++) {
    fin >> get<1>(M[i]); // id
    string S;
    fin >> S;
    for (auto j=0; j<25; j++) {
      int l;
      fin >> l;
      get<2>(M[i]).push_back(l);
    }
    fin >> get<0>(M[i]); // score
  }
}

void koushin_score() {
  string S = query("https://game.coderunner.jp/scorelist");
  // cout << S << endl;
  stringstream ss(S);
  int temp[1000];
  for (auto i=0; i<1000; i++) {
    string t;
    ss >> t;
    temp[i] = stoi(t);
  }
  for (auto i=0; i<1000; i++) {
    for (auto j=0; j<1000; j++) {
      if (get<1>(M[j]) == i) {
        get<0>(M[j]) = temp[i];
        break;
      }
    }
  }  
  sleep(1);
}

void init_player() {
  string url = "https://game.coderunner.jp/info.txt?token=" + token;
  string result = query(url);
  cout << result << endl;
  stringstream ss(result);
  string t;
  ss >> t;
  ss >> t;
  for (auto i=0; i<25; i++) {
    ss >> t;
    have[i] = stoi(t);
  }
  for (auto i=0; i<25; i++) {
    for (auto j=0; j<25; j++) {
      ss >> t;
      koukan[i][j] = stoi(t);
    }
  }
  sleep(1);
}

void torihiki_a(int in, int out, int num) {
  string url = "https://game.coderunner.jp/trade?token=" + token 
    + "&in=" + to_string(in) + "&out=" + to_string(out) 
    + "&num=" + to_string(num);
  string res = query(url);
  cout << "in: " << in << " out: " 
       << out << " num: " << num << " res: "<< res << endl;
  sleep(1);
}

void torihiki_up(int group) {
  int st = group * 5;
  int sum = 0;
  for (auto i=0; i<5; i++) {
    sum += have[i+st];
  }
  int av = sum/5;
  for (auto i=0; i<5; i++) {
    if (have[i+st] < av) {
      for (auto j=0; j<5; j++) {
        if ((have[j+st] > av) && (i != j)) {
          torihiki_a(i+st, j+st, have[j+st]/5);
        }
      }
    }
  }
}

string shokan_a(int monster) {
  string url = "https://game.coderunner.jp/summon?token=" + token 
    + "&monster=" + to_string(monster);
  string res = query(url);
  sleep(1);
  return res;
}

void shokan(int group) {
  int ng = 0;
  int ng_u = (5-group)*2-1;
  while (true) {
    init_player();
    koushin_score();
    // torihiki_up(group);
    sort(M+s_d[group], M+s_u[group]);
    reverse(M+s_d[group], M+s_u[group]);
  IAAA:
    for (auto i=s_d[group]; i<s_u[group]; i++) {
      for (auto j=0; j<25; j++) {
        if (get<2>(M[i])[j] > have[j]) {
          goto EXIT;
        }
      }
      if (group > 0 && prev_score[group-1] > get<0>(M[i])) {
        cerr << "pass" << endl;
        return;
      }
      cout << "no: " << get<1>(M[i]) << " score: " << get<0>(M[i]) << endl;
      prev_score[group] = get<0>(M[i]);
      if (shokan_a(get<1>(M[i])) != "OK") {
        ng++;
        if (ng == ng_u) {
          return;
        }
      } else {
        goto IAAA;
      }
    EXIT: continue;
    }
    return;
  }
}
 
int main() {
  fill(prev_score, prev_score+5, 0);
  init_monster();
  for (auto i=0; i<1000; i++) {
    shokan(i%5);
  }
}
