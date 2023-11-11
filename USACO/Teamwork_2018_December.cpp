#include <bits/stdc++.h>
using namespace std;
#define int long long

void testcase() {
    int n, k;
    cin >> n >> k;

    vector<int> skill(n + 1), dp(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> skill[i];
    }

    dp[1] = skill[1];
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1] + skill[i];
        for (int j = i, highestSkill = skill[j]; j > max(0ll, i - k); j--) {
            highestSkill = max(highestSkill, skill[j]);
            dp[i] = max(dp[i], dp[j - 1] + highestSkill * (i - j + 1));
        }
    }

    cout << dp[n];
}

int32_t main() {
    freopen("teamwork.in", "r", stdin);
    freopen("teamwork.out", "w", stdout);

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int tc = 1;
    // cin >> tc;
    for (int i = 1; i <= tc; i++) {
        // cout << "Case #" << i << ": ";
        testcase();
    }
    return 0;
}
