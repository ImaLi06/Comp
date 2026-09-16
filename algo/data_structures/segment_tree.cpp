template <typename T, T (*oper)(T, T)> struct STree {
  vector<T> st;
  int n;
  T NEUT;
  STree(int n, T neut) : st(4 * n + 5, neut), n(n), NEUT(neut) {}
  void init(int k, int s, int e, T *a) {
    if (s + 1 == e) {
      st[k] = a[s];
      return;
    }
    int m = (s + e) / 2;
    init(2 * k, s, m, a);
    init(2 * k + 1, m, e, a);
    st[k] = oper(st[2 * k], st[2 * k + 1]);
  }
  void upd(int k, int s, int e, int p, T v) {
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
  T query(int k, int s, int e, int a, int b) {
    if (s >= b || e <= a)
      return NEUT;
    if (s >= a && e <= b)
      return st[k];
    int m = (s + e) / 2;
    return oper(query(2 * k, s, m, a, b), query(2 * k + 1, m, e, a, b));
  }
  void init(T *a) { init(1, 0, n, a); }
  void upd(int p, T v) { upd(1, 0, n, p, v); }
  T query(int a, int b) { return query(1, 0, n, a, b); }
};
