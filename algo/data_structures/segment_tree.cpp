struct STree {
  typedef ll tn;                // node type
  static constexpr tn NEUT = 0; // operation neutral
  static tn oper(tn a, tn b) { return a + b; }
  vector<tn> st;
  int n;
  STree(int n) : st(4 * n + 5, NEUT), n(n) {}
  void init(int k, int s, int e, vector<tn> &a) {
    if (s + 1 == e) {
      st[k] = a[s];
      return;
    }
    int m = (s + e) / 2;
    init(2 * k, s, m, a);
    init(2 * k + 1, m, e, a);
    st[k] = oper(st[2 * k], st[2 * k + 1]);
  }
  void upd(int k, int s, int e, int p, tn v) {
    if (s + 1 == e) {
      st[k] = v;
      return;
    }
    int m = (s + e) / 2;
    if (p < m)
      upd(2 * k, s, m, p, v);
    else
      upd(2 * k + 1, m, e, p, v);
    st[k] = oper(st[2 * k], st[2 * k + 1]);
  }
  tn query(int k, int s, int e, int a, int b) {
    if (e <= a || b <= s)
      return NEUT;
    if (a <= s && e <= b)
      return st[k];
    int m = (s + e) / 2;
    return oper(query(2 * k, s, m, a, b), query(2 * k + 1, m, e, a, b));
  }
  void init(vector<tn> &a) { init(1, 0, n, a); }
  void upd(int p, tn v) { upd(1, 0, n, p, v); }           // a[p] = v
  tn query(int a, int b) { return query(1, 0, n, a, b); } // [a,b)
};
