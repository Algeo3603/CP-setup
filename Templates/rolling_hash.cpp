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


// p should be prime and roughly equal to number of characters in input alphabet
// p = 31 or 29 for the alphabet upper or lowercase
// p = 53 or 47 or 59 for upper and lowercase
// use large prime for performing mod, 1e9+9 or 1e9+7
const int N = 1e6;
const long long MOD = 1e9 + 9;
const long long P = 31;
vector<long long> p_power_exp(N + 1);
vector<long long> inv_p_power_exp(N + 1);
// const long long Q = ?;
// vector<long long> q_power_exp(N + 1);
// vector<long long> inv_q_power_exp(N + 1);


void precompute(int power, vector<long long> &power_exp, vector<long long> &inv_power_exp) {
    power_exp[0] = 1;
    for (int i = 1; i <= N; i++) {
        power_exp[i] = (power_exp[i - 1] * power) % MOD;
    }

    inv_power_exp[N] = mod_inv(power_exp[N], MOD);
    for (int i = N - 1; i >= 0; i--) {
        inv_power_exp[i] = (power * inv_power_exp[i + 1]) % MOD;
    }
}


vector<long long> compute_hashes(string const& s, vector<long long> &power_exp) {
    int n = s.size();
    vector<long long> hash(n);
    hash[0] = (s[0] - 'a' + 1) * power_exp[0];
    // cout << hash[0] << "\n";
    for (int i = 1; i < n; i++) {
        hash[i] = (hash[i - 1] + (s[i] - 'a' + 1) * power_exp[i]) % MOD;
        // cout << hash[i] << "\n";
    }
    return hash;
}


long long getHash(int i, int j, vector<long long> &hash, vector<long long> &inv_power_exp) {
    int res = (hash[j] - (i == 0 ? 0 : hash[i - 1]) + MOD) % MOD;
    res = (res * inv_power_exp[i]) % MOD;
    return res;
}
