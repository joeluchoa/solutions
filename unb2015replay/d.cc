#include <bits/stdc++.h>

using namespace std;

#define rep(i,n) for (int (i)=0; (i)<(n); ++(i))
#define all(x) (x).begin(),(x).end()
#define dbg(x) cerr << #x << " = " << x << endl
#define sz(x) (int)((x).size())
#define ms(m,v) memset((m), (v), sizeof (m))
#define mp make_pair
#define pb push_back


int n;

struct T {
  double m[5][5];

  T() { ms(m,0); }

  T operator*(const T& o) const {
    T r;
    rep(i,n) rep(j,n) rep(k,n) r.m[i][j] += m[i][k] * o.m[k][j];
    return r;
  }
};

T g;

T exp(T a, int b) {
  if (b == 1) return a;
  if (b&1) return exp(a, b - 1) * a;
  T x = exp(a, b/2);
  return x * x;
}

int main() {
  while (cin >> n) {
    rep(i,n) rep(j,n) cin >> g.m[i][j];
    int q;
    cin >> q;
    while (q--) {
      int i,j,k;
      cin >> j >> i >> k;
      printf("%lf\n", exp(g,k).m[i-1][j-1]);
    }
  }

  return 0;
}
