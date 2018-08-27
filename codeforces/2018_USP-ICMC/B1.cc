#include <bits/stdc++.h>

using namespace std;

void zf(vector<int> &z, string &s) {
  int n = s.size();
  int L, R, k;
  L = R = 0;
  z.resize(n);
  z[0] = n;
  for (int i = 1; i < n; ++i) {
    if (R < i) {
      L = R = i;
      while (R < n && s[R-L] == s[R]) ++R;
      z[i] = R-L;
      --R;
    } else {
      k = i - L;
      if (z[k] <= R-i) {
        z[i] = z[k];
      } else {
        L = i;
        while (R < n && s[R-L] == s[R]) ++R;
        z[i] = R-L;
        --R;
      }
    }
  }
}

int main() {
  int n;
  string s;

  cin >> n >> s;
  s += s;

  vector<int> z;
  zf(z,s);

  bool ok = true;
  for (int i = 1; i < n; ++i)
    if (z[i] < n && s[z[i]] > s[i+z[i]])
      ok = false;

  cout << (ok ? "Yes" : "No") << endl;

  return 0;
}
