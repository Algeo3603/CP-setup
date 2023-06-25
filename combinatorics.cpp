const int MOD = 1000000007;
// const int MOD = 998244353;
const ld PI = 3.141592653589793238462;

int bin_expo(int a, int b, int m) {
    int res = 1; 
    while (b > 0) {
        if (b & 1) {
            res = (res * a) % m;
        }
        a = (a * a) % m; b = b >> 1;
    }
    return res;
}

int mod_inv(int a, int b) {
    return bin_expo(a, b - 2, b);
} // only for prime b

const int N = ?;
vector<int> fact(N+1), invFact(N+1);
void generateFactorials() {
    fact[0] = 1;
    for (int i = 1; i <= N; ++i)
        fact[i] = i * fact[i-1] % MOD;
    invFact[N] = mod_inv(fact[N], MOD);
    for (int i = N - 1; i >= 0; --i)
        invFact[i] = (i+1) * invFact[i+1] % MOD;
}

int ncr(int n, int r) {
    if (r > n || n < 0 || r < 0) return 0;
    return fact[n] * invFact[r] % MOD * invFact[n-r] % MOD;
}

int npr(int n, int r) {
    if (r > n || n < 0 || r < 0) return 0;
    return fact[n] * invFact[n-r] % MOD;
}
