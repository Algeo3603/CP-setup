const int MOD = 1000000007;
// const int MOD = 998244353;

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
