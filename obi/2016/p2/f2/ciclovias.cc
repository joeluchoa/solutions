#include <bits/stdc++.h>

using namespace std;

#define rep(i,n) for (int i=0; i<(n); ++i)
#define all(x) x.begin(),x.end()
#define dbg(x) cerr << #x << " = " << x << endl
#define sz(x) (int)(x.size())
#define ms(m,v) memset((m), (v), sizeof (m))
#define mp make_pair
#define pb push_back
#define _ << ", " <<
#define endl "\n"

typedef long long ll;

const int MAXN = 500100;

int n, m;
vector<int> g[MAXN];
int maxPath[MAXN];

main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int v, u;
    scanf("%d %d", &v, &u);
    g[v].pb(u);
    g[u].pb(v);
  }

  for (int i = 1; i <= n; ++i)
    maxPath[i] = 1, sort(all(g[i]));

  for (int v = n; v >= 1; --v) {
    int best = 0;
    for (int j = g[v].size() - 1; j >= 0; --j) {
      int u = g[v][j];
      int aux = max(maxPath[u], best + 2);
      best = max(maxPath[u], best);
      maxPath[u] = aux;
    }
  }

  for (int v = 1; v <= n; ++v)
    printf("%d ", maxPath[v]);
  puts("");
}
