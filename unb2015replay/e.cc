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
  int t, T = 0;
  for (cin >> t; t--;) {
    string s;
    cin >> s;
    int a, b, c;
    cin >> a >> b >> c;
    int p=0;
    if (s == "min") p = min(a, min(b,c));
    if (s == "max") p = max(a, max(b,c));
    if (s == "mean") p = (a+b+c)/3;
    if (s == "eye") p = 0.3 * a + 0.59*b + 0.11 * c;
    printf("Caso #%d: %d\n", ++T, p);
  }
  return 0;
}
