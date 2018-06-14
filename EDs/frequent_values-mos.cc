#include <bits/stdc++.h>

using namespace std;

#define rep(i,n) for (int i=0; i<(n); ++i)
#define all(x) x.begin(),x.end()
#define dbg(x) cerr << #x << " = " << x << endl
#define sz(x) (int)(x.size())
#define ms(m,v) memset((m), (v), sizeof (m))
#define mp make_pair
#define pb push_back
#define endl "\n"

const int MAXN = 200100;
const int S = 100000;
const int B = 350;

struct T {
  int i, j, idx;

  bool operator<(const T &o) const {
    int x = i / B, y = o.i / B;
    if (x != y) return x < y;
    return j < o.j;
  }
};

int n, q;
int a[MAXN];
T seg[MAXN];
int sol[MAXN];

int f[MAXN], ff[MAXN], maximum;

void init() {
  ms(f, 0);
  ms(ff, 0);
  maximum = 0;
}

void include(int v) {
  --ff[f[v]++];
  ++ff[f[v]];
  maximum = max(maximum, f[v]);
}

void exclude(int v) {
  --ff[f[v]--];
  ++ff[f[v]];
  if (ff[maximum] == 0) --maximum;
}

int val(int v) { return S + v; }

void mos() {
  int I = seg[0].i, J = seg[0].i-1;

  sort(seg, seg + q);
  init();

  for (int i = 0; i < q; ++i) {
    while (J < seg[i].j) include(val(a[++J]));
    while (J > seg[i].j) exclude(val(a[J--]));
    while (I < seg[i].i) exclude(val(a[I++]));
    while (I > seg[i].i) include(val(a[--I]));
    sol[seg[i].idx] = maximum;
  }
}

int main() {

  while (scanf("%d %d", &n, &q) == 2 && n) {
    rep(i, n) scanf("%d", &a[i]);
    rep(i, q) {
      scanf("%d %d", &seg[i].i, &seg[i].j);
      seg[i].i--, seg[i].j--, seg[i].idx = i;
    }

    mos();
    for (int i = 0; i < q; ++i)
      printf("%d\n", sol[i]);
  }

  return 0;
}
