#include <bits/stdc++.h>

using namespace std;

#define rep(i,n) for (int (i)=0; (i)<(n); ++(i))
#define all(x) (x).begin(),(x).end()
#define dbg(x) cerr << #x << " = " << x << endl
#define sz(x) (int)((x).size())
#define ms(m,v) memset((m), (v), sizeof (m))
#define mp make_pair
#define pb push_back

#define v(c) (c-'a'+1)

int main() {
  int n, k;

  while (cin >> n >> k) {
    string s;
    cin >> s;

    int dp[27];
    ms(dp,0);
    for (auto i : s)
      for (char c = i; c >= 'a'; --c)
        dp[v(i)] = max(dp[v(i)], dp[v(c)] + (27-v(i)));
    int sol = 0;
    rep(i,26) sol = max(sol, dp[i+1]);
    cout << (sol >= k ? "Aceita" : "Rejeita") << endl;
  }

  return 0;
}
