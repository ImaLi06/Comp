const int SIEVE_MAX = 1000000;

int spf[SIEVE_MAX + 1];
void sieve() {
  for (int i = 1; i <= SIEVE_MAX; ++i)
    spf[i] = i;

  for (int i = 2; i * i <= SIEVE_MAX; ++i) {
    if (spf[i] == i) {
      for (int j = i * i; j <= SIEVE_MAX; j += i) {
        if (spf[j] == j) {
          spf[j] = i;
        }
      }
    }
  }
}
