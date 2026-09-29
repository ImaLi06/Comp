ll extgcd(ll a, ll b, ll &x, ll &y) { // a*x + b*y = gcd(a,b)
  if (!b) {
    x = 1, y = 0;
    return a;
  }
  ll g = extgcd(b, a % b, y, x);
  y -= a / b * x;
  return g;
}
ll inv(ll a, ll m) { // a^-1 mod m, -1 if gcd(a,m) != 1
  ll x, y;
  a %= m;
  if (a < 0)
    a += m;
  if (extgcd(a, m, x, y) != 1)
    return -1;
  return (x % m + m) % m;
}
// prime p: inv(a) = binpow(a, p - 2, p)
// all inverses 1..n mod prime p, O(n):
// iv[1] = 1; for i in [2,n]: iv[i] = (p - p / i) * iv[p % i] % p;
