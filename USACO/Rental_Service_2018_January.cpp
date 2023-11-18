#include <bits/stdc++.h>
using namespace std;
#define int long long

int N, M, R;
vector<int> cows;
vector<pair<int, int>> stores;
vector<pair<int, int>> psumStores;
vector<int> rents;

int sellMilk(int gallons) {
    int l = 0, r = M - 1;
    while (l < r) {
        int mid = (l + r) / 2;

        if (psumStores[mid].first <= gallons) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }

    if (r == 0) {
        return gallons * stores[r].first;
    } else if (gallons >= psumStores[M - 1].first) {
        return psumStores[M - 1].second;
    }
    return psumStores[r - 1].second + (gallons - psumStores[r - 1].first) * stores[r].first;
}

void testcase() {
    cin >> N >> M >> R;
    cows.resize(N);
    stores.resize(M);
    psumStores.resize(M);
    rents.resize(R);

    for (auto &i: cows) cin >> i;
    for (auto &i: stores) cin >> i.second >> i.first;
    for (auto &i: rents) cin >> i;

    sort(cows.rbegin(), cows.rend());
    sort(stores.rbegin(), stores.rend());
    sort(rents.rbegin(), rents.rend());

    for (int i = 1; i < N; i++) {
        cows[i] += cows[i - 1];
    } for (int i = 0; i < M; i++) {
        psumStores[i].first = stores[i].second + (i == 0 ? 0 : psumStores[i - 1].first);
        psumStores[i].second = (stores[i].first * stores[i].second) + (i == 0 ? 0 : psumStores[i - 1].second);
    } for (int i = 1; i < R; i++) {
        rents[i] += rents[i - 1];
    }

    int ans = rents[min(N, R) - 1];
    // sell milk till the ith cow, rent the remining cows
    for (int i = 0; i < N; i++) {
        int cowsToRent = min(N - i - 1, R);
        int profit = (cowsToRent > 0 ? rents[cowsToRent - 1] : 0) + sellMilk(cows[i]);
        ans = max(ans, profit);
    }

    cout << ans;
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("rental.in", "r", stdin);
    freopen("rental.out", "w", stdout);

    int tc = 1;
    // cin >> tc;
    for (int i = 1; i <= tc; i++) {
        // cout << "Case #" << i << ": ";
        testcase();
    }
    return 0;
}
