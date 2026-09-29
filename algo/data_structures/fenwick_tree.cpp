struct FTree {
  typedef ll tn;
  static constexpr tn NEUT = 0;
  static tn oper(tn a, tn b) { return a + b; }
  vector<tn> ft;
  int n;
  FTree(int n) : ft(n + 1, NEUT), n(n) {} // build: for i in [0,n): upd(i, a[i])
  void upd(int p, tn v) {                 // a[p] = oper(a[p], v)
    for (int i = p + 1; i <= n; i += i & -i)
      ft[i] = oper(ft[i], v);
  }
  tn get(int p) { // oper of [0,p)
    tn r = NEUT;
    for (int i = p; i; i -= i & -i)
      r = oper(r, ft[i]);
    return r;
  }
  tn query(int a, int b) {
    return get(b) - get(a);
  } // [a,b), inverse of oper (xor: ^)
};
// *min/max: only prefix get(), and updates may only improve a[p]
