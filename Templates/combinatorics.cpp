const long long MOD = 1000000007;
// const long long MOD = 998244353;
const long double PI = 3.141592653589793238462;


long long bin_expo(long long a, long long b, long long m) {
    long long res = 1; 
    while (b > 0) {
        if (b & 1) {
            res = (res * a) % m;
        }
        a = (a * a) % m; b = b >> 1;
    }
    return res;
}


long long mod_inv(long long a, long long m) {
    return bin_expo(a, m - 2, m);
} // only for prime b


const int N = ?;
vector<long long> fact(N+1), invFact(N+1);
void generateFactorials() {
    fact[0] = 1;
    for (int i = 1; i <= N; ++i)
        fact[i] = i * fact[i-1] % MOD;
    invFact[N] = mod_inv(fact[N], MOD);
    for (int i = N - 1; i >= 0; --i)
        invFact[i] = (i+1) * invFact[i+1] % MOD;
}


long long ncr(int n, int r) {
    if (r > n || n < 0 || r < 0) return 0ll;
    return fact[n] * invFact[r] % MOD * invFact[n-r] % MOD;
}


long long npr(int n, int r) {
    if (r > n || n < 0 || r < 0) return 0ll;
    return fact[n] * invFact[n-r] % MOD;
}
