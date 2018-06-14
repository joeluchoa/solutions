#include <bits/stdc++.h>

using namespace std;

typedef long long lli;

struct AVL {

  struct Node {
    int sz, h, v;
    lli sum;
    Node *l, *r;

    Node(int v) : v(v) {
      l = r = NULL;
      sz = 1;
      h = 0;
      sum = v;
    }
  };

  typedef Node* pNode;

  pNode root;

  AVL() {
    root = NULL;
  }

  int sz(pNode &t) { return t == NULL ? 0 : t->sz; }
  int h(pNode &t) { return t == NULL ? -1 : t->h; }
  lli sum(pNode &t) { return t == NULL ? 0 : t->sum; }
  bool ck(pNode &t) { return abs(h(t->l)-h(t->r)) <= 1; }

  void upd(pNode &t) {
    if (t != NULL) {
      t->sz = sz(t->l) + sz(t->r) + 1;
      t->h = max(h(t->l), h(t->r)) + 1;
      t->sum = sum(t->l) + sum(t->r) + t->v;
    }
  }

  void ll(pNode &t) {
    //if (t->r == NULL) puts("!!! LL");
    pNode aux = t->r;
    t->r = aux->l;
    aux->l = t;
    t = aux;
    upd(t->l);
    upd(t->r);
    upd(t);
  }

  void rr(pNode &t) {
    //if (t->l == NULL) puts("!!!");
    pNode aux = t->l;
    t->l = aux->r;
    aux->r = t; 
    t = aux;
    upd(t->r);
    upd(t->l);
    upd(t);
  }

  void rl(pNode &t) { if (t!=NULL) rr(t->r), ll(t); }
  void lr(pNode &t) { if (t!=NULL) ll(t->l), rr(t); }

  void balance(pNode &t) {
    //printf("{{{%d %d}}}\n", h(t->r), h(t->l));
    if (h(t->r) > h(t->l)) {
      int x = t->r!=NULL ? h(t->r->r) : -1;
      int y = t->r!=NULL ? h(t->r->l) : -1;
      if (x > y) ll(t);
      else rl(t);
    } else {
      int x = t->l!=NULL ? h(t->l->l) : -1; 
      int y = t->l!=NULL ? h(t->l->r) : -1; 
      //printf("*** {{{%d %d}}}\n", x, y);
      if (x >= y) rr(t);
      else lr(t);
    }
  }

  void insert(int p, int v, pNode &t) {
    if (t == NULL) {
      //printf("[%d]\n", p);
      t = new Node(v);
    } else {
      if (sz(t->l)+1 <= p)
        insert(p - sz(t->l)-1, v, t->r);
      else
        insert(p, v, t->l);

      upd(t);
      if (!ck(t)) balance(t);
    }
  }

  void insert(int p, int v) {
    insert(p, v, root);
  }

  lli query(int i, int j, pNode &t) {
    if (t == NULL || sz(t) < i || j <= 0) return 0;
    if (i <= 0 && sz(t) <= j) return t->sum;
    lli s = query(i,j, t->l) + query(i-sz(t->l)-1,j-sz(t->l)-1, t->r);
    if (i <= sz(t->l)+1 && sz(t->l)+1 <= j)
      s += t->v;
    return s;
  }

  lli query(int i, int j) {
    return query(i, j, root);
  }

  void p(pNode &t) {
    if (t == NULL) return;
    else {
      printf("(");
      p(t->l);
      printf(" %d [%d,%d] ", t->v, t->h, t->sz);
      p(t->r);
      printf(")");
    }
  }
};

int main() {
  int n, q;
  AVL t;

  scanf("%d", &n);
  for (int i = 0, v; i < n; ++i) {
    scanf("%d", &v);
    t.insert(i, v);
    //t.p(t.root); puts("");
  }

  scanf("%d", &q);
  while (q--) {
    char c;
    int i,j;
    scanf(" %c %d %d", &c, &i, &j);
    //printf(">> %d %d\n", i, j);
    if (c == 'S') {
      printf("%lld\n", t.query(i, j));
    } else {
      t.insert(i, j);
      //t.p(t.root); puts("");
    }
  }
}
