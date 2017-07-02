#include <bits/stdc++.h>

using namespace std;

#define rep(i,n) for (int (i)=0; (i)<(n); ++(i))
#define all(x) (x).begin(),(x).end()
#define dbg(x) cerr << #x << " = " << x << endl
#define sz(x) (int)((x).size())
#define ms(m,v) memset((m), (v), sizeof (m))
#define mp make_pair
#define pb push_back

const int MAXN = 110;
const int INF = 0x3f3f3f3f;

int n, m;
int v[MAXN];
int g[MAXN][MAXN];
int s[MAXN], ns;

bool prime(int x) {
  if (x == 2) return true;
  if (x % 2 == 0) return false;
  for (int i = 3; i * i <= x; i += 2)
    if (x % i == 0)
      return false;
  return true;
}

int memo[1<<17][17];
int go(int mask, int v) {
  if (mask == (1<<ns) - 1) return g[s[v]][s[0]];

  int &ref = memo[mask][v];
  if (ref == -1) {
    ref = INF;
    for (int u = 0; u < ns; ++u) if (!(mask&(1<<u))) {
      int aux = g[s[v]][s[u]] + go(mask|(1<<u),u);
      if (aux < ref) ref = aux;
    }
  }

  return ref;
}

int main() {

  while (scanf("%d %d", &n, &m) == 2) {
    rep(i,n) scanf("%d", &v[i+1]);
    ms(g, INF);
    while (m--) {
      int a, b, c;
      scanf("%d %d %d", &a, &b, &c);
      g[a][b] = g[b][a] = c;
    }

    for (int k = 1; k <= n+1; ++k)
      for (int i = 1; i <= n+1; ++i)
        for (int j = 1; j <= n+1; ++j)
          if (g[i][j] > g[i][k]+g[k][j])
            g[i][j] = g[i][k]+g[k][j];

    s[0] = n+1;
    ns = 1;
    for (int i = 1; i <= n; ++i)
      if (prime(v[i]))
        s[ns++] = i;

    ms(memo, -1);
    printf("%d\n", go(1,0));

  }
  return 0;
}
