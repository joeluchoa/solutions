#include <bits/stdc++.h>

using namespace std;

#define rep(i,n) for (int (i)=0; (i)<(n); ++(i))
#define all(x) (x).begin(),(x).end()
#define dbg(x) cerr << #x << " = " << x << endl
#define sz(x) (int)((x).size())
#define ms(m,v) memset((m), (v), sizeof (m))
#define mp make_pair
#define pb push_back

int main() {
  int n;
  while (cin >> n) {
    pair<int, string> v[n];
    rep(i,n) cin >> v[i].second >> v[i].first;
    sort(v,v+n);
    rep(i,n) cout << v[i].second << (i<n-1?" ":"");
    puts("");
  }
  return 0;
}
