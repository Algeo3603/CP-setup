const long long MOD = 1000000007;
// const long long MOD = 998244353;


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
