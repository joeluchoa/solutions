#include <bits/stdc++.h>
 
using namespace std;
 
struct T {
  int cnt;
  T *c[26];
 
  T() {
    cnt = 0;
    memset(c, 0, sizeof c);
  }
 
  void add(string &s, int i=0) {
    ++cnt;
    if (i == s.size()) return;
    if (c[s[i]-'a'] == NULL)
      c[s[i]-'a'] = new T();
    c[s[i]-'a']->add(s, i + 1);
  }
 
  int count(string &s, int i=0) {
    if (i == s.size()) return cnt;
    if (c[s[i]-'a'] == NULL) return 0;
    return c[s[i]-'a']->count(s,i+1);
  }
};
 
int main() {
  std::ios::sync_with_stdio(false); cin.tie(0);
  int n, q;
  string s;
 
  cin >> n >> q >> s;
 
  T trie;
  for (int i = 0; i < n; ++i)
    trie.add(s, i);
 
  while (q--) {
    string p;
    cin >> p;
    cout << trie.count(p) << endl;
  }
 
  return 0;
}
