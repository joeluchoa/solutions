#include <bits/stdc++.h>

using namespace std;

#define rep(i,n) for (int (i)=0; (i)<(n); ++(i))
#define all(x) (x).begin(),(x).end()
#define dbg(x) cerr << #x << " = " << x << endl
#define sz(x) (int)((x).size())
#define ms(m,v) memset((m), (v), sizeof (m))
#define mp make_pair
#define pb push_back

map<string, map<string, bool> > m;
string msg[] = {
  "Os atributos dos monstros vao ser inteligencia, sabedoria...",
  "Iron Maiden's gonna get you, no matter how far!",
  "Urano perdeu algo muito precioso...",
  "Putz vei, o Leo ta demorando muito pra jogar..."
};

void init() { m["papel"]["pedra"] = m["pedra"]["tesoura"] = m["tesoura"]["papel"] = true; }

int main() {
  string a, b, c;
  init();
  while (cin >> a >> b >> c) {
    if (m[a][b] && m[a][c]) cout << msg[0] << endl;
    else if (m[b][a] && m[b][c]) cout << msg[1] << endl;
    else if (m[c][a] && m[c][b]) cout << msg[2] << endl;
    else cout << msg[3] << endl;
  }
  return 0;
}
