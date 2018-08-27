#include <bits/stdc++.h>

using namespace std;

struct T {
  int idx;
  int x,y;
  T(int i=0, int x=0, int y=0) {
    idx = i;
    this->x = x;
    this->y = y;
  }

  bool operator<(const T &o) const {
    return x != o.x ? x < o.x : y < o.y;
  }

  bool operator!=(const T &o) const {
    return x != o.x || y != o.y;
  }
};

void sa_build(vector<int> &sa, string &s) {
  int n = s.size();
  int rank[n];
  T ord[n];

  for (int i = 0; i < n; ++i) {
    ord[i].idx = i;
    ord[i].x = -1;
    ord[i].y = s[i]-'0';
  }
  stable_sort(ord, ord + n);

  for (int i = 1; i <= n; i *= 2) {
    int r = 0;
    rank[0] = 0;
    for (int j = 1; j < n; ++j) {
      if (ord[j] != ord[j-1])
        ++r;
      rank[ord[j].idx] = r;
    }

    for (int j = 0; j < n; ++j) {
      ord[j].x = rank[ord[j].idx];
      if (ord[j].idx+i >= n)
        ord[j].y = -1;
      else
        ord[j].y = rank[ord[j].idx+i];
    }
    stable_sort(ord, ord + n);
  }

  sa.resize(n);
  for (int i = 0; i < n; ++i)
    sa[i] = ord[i].idx;
}

int main() {
  int n;
  string s;
  cin >> n >> s;
  s += s + char('9'+1);

  vector<int> sa;
  sa_build(sa,s);
  //for (int i : sa) cout << i << " ";

  cout << (sa[0] != 0 ? "No" : "Yes") << endl;

  return 0;
}

