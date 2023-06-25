#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define pb push_back
#define cy cout << "YES\n"
#define cn cout << "NO\n"
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define bug(...) __f(#__VA_ARGS__, __VA_ARGS__);
const int MOD = 1000000007;
// const int MOD = 998244353;
const ld PI = 3.141592653589793238462;

template <typename Arg1>
void __f (const char* name, Arg1&& arg1) {cout << name << " : " << arg1 << endl;}
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{
    const char* comma = strchr (names + 1, ',');
    cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}

int lcm(int a, int b) {return (a * b) / __gcd(a, b);}
int bin_expo(int a, int b, int m) {int res = 1; while (b > 0){ if (b & 1) res = (res * a) % m; a = (a * a) % m; b = b >> 1;} return res;}
int mod_inv(int a, int b) {return bin_expo(a, b - 2, b);} // only for prime b
/******************************************************************************************/

void solve()
{}

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
    
    return 0;
}

