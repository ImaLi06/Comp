ll binpow(ll a, ll e, ll m) { // a^e mod m, e >= 0, m < ~3e9
  ll r = 1 % m;
  a %= m;
  if (a < 0)
    a += m;
  while (e) {
    if (e & 1)
      r = r * a % m;
    a = a * a % m;
    e >>= 1;
  }
  return r;
}
// a^-1 mod p for prime p, a % p != 0: binpow(a, p - 2, p)
