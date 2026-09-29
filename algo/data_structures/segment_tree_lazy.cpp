struct STreeL {
  typedef ll tn;                 // node type
  typedef ll tl;                 // lazy type
  static constexpr tn NEUT = 0;  // operation neutral
  static constexpr tl CLEAR = 0; // cleared lazy
  static tn oper(tn a, tn b) { return a + b; }
  static void acum(tl &a, tl v) { a += v; } // compose lazies
  static tn calc(int s, int e, tn a, tl v) {
    return a + (e - s) * v;
  } // apply lazy
  vector<tn> st;
  vector<tl> lazy;
  int n;
  STreeL(int n) : st(4 * n + 5, NEUT), lazy(4 * n + 5, CLEAR), n(n) {}
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
  void push(int k, int s, int e) {
    if (lazy[k] == CLEAR)
      return;
    st[k] = calc(s, e, st[k], lazy[k]);
    if (s + 1 != e) {
      acum(lazy[2 * k], lazy[k]);
      acum(lazy[2 * k + 1], lazy[k]);
    }
    lazy[k] = CLEAR;
  }
  void upd(int k, int s, int e, int a, int b, tl v) {
    push(k, s, e);
    if (e <= a || b <= s)
      return;
    if (a <= s && e <= b) {
      acum(lazy[k], v);
      push(k, s, e);
      return;
    }
    int m = (s + e) / 2;
    upd(2 * k, s, m, a, b, v);
    upd(2 * k + 1, m, e, a, b, v);
    st[k] = oper(st[2 * k], st[2 * k + 1]);
  }
  tn query(int k, int s, int e, int a, int b) {
    if (e <= a || b <= s)
      return NEUT;
    push(k, s, e);
    if (a <= s && e <= b)
      return st[k];
    int m = (s + e) / 2;
    return oper(query(2 * k, s, m, a, b), query(2 * k + 1, m, e, a, b));
  }
  void init(vector<tn> &a) { init(1, 0, n, a); }
  void upd(int a, int b, tl v) { upd(1, 0, n, a, b, v); } // [a,b) += v
  tn query(int a, int b) { return query(1, 0, n, a, b); } // [a,b)
};
