#include <bits/stdc++.h>

using namespace std;

#define rep(i,n) for (int (i)=0; (i)<(n); ++(i))
#define all(x) (x).begin(),(x).end()
#define dbg(x) cerr << #x << " = " << x << endl
#define sz(x) (int)((x).size())
#define ms(m,v) memset((m), (v), sizeof (m))
#define mp make_pair
#define pb push_back

int c(char ch) { return ch - 'a'; }

struct T {
  int qtd;
  int tam;
  T* t[26];

  T() { qtd = tam = 0; ms(t, 0); }

  void add(string &s, int i=0) {
    tam = max(tam, sz(s));
    ++qtd;
    if (i == sz(s)-1) return;
    if (t[c(s[i])] == NULL) t[c(s[i])] = new T();
    t[c(s[i])]->add(s,i+1);
  }

  pair<int, int> get(string &s, int i=0) {
    if (i == sz(s)-1) return mp(qtd,tam);
    if (t[c(s[i])] == NULL) return mp(-1,-1);
    return t[c(s[i])]->get(s,i+1);
  }
};

int main() {
  int n;
  while (cin >> n) {
    string s;
    T t;
    rep(i, n) cin >> s, t.add(s);
    int q;
    for (cin >> q;q--;) {
      cin >> s;
      pair<int,int> p = t.get(s);
      if (p.first == -1) cout << p.first << endl;
      else cout << p.first << " " << p.second << endl;
    }
  }
  return 0;
}
