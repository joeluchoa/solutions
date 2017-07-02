#include <bits/stdc++.h>

using namespace std;

#define rep(i,n) for (int (i)=0; (i)<(n); ++(i))
#define all(x) (x).begin(),(x).end()
#define dbg(x) cerr << #x << " = " << x << endl
#define sz(x) (int)((x).size())
#define ms(m,v) memset((m), (v), sizeof (m))
#define mp make_pair
#define pb push_back

int n, m, q;
vector<int> g[10100];
int c[10100], nc;

void dfs(int v) {
  c[v] = nc;
  for (auto u : g[v]) if (c[u] == -1) dfs(u);
}

int main() {
  int ok = 0;
  while (cin >> n >> m >> q) {
    if (ok)
      puts("");
    ok = 1;
    rep(i,n+1) g[i].clear();
    while (m--) {
      int a, b;
      scanf("%d %d", &a, &b);
      g[a].pb(b);
      g[b].pb(a);
    }
    ms(c,-1), nc = 0;
    rep(i,n) if (c[i+1]==-1) ++nc, dfs(i+1);
    while (q--) {
      int a, b;
      cin >> a >> b;
      cout << (c[a]==c[b] ? "S" : "N") << endl;
    }
  }
  return 0;
}
