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
  string s;

  cin >> s;
  int n = s.size();

  vector<int> z;
  zf(z,s);

  vector<int> ms(n+1, 0);
  for (int i = n - 1; i >= 0; --i) {
    if (i+z[i] == n)
      ms[i] = z[i];
    else
      ms[i] = ms[i+1];
  }

  int sol = 0, p;
  for (int i = 1; i < n-1; ++i) {
    int x = n-z[i];
    if (x <= i)
      ++x;
    if (ms[x] > sol)
      sol = ms[x], p = i;
  }


  if (sol == 0)
    puts("Just a legend");
  else
    cout << s.substr(p,sol) << endl;

  return 0;
}

