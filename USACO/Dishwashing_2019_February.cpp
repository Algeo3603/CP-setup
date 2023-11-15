#include <bits/stdc++.h>
using namespace std;
#define int long long

int N;
vector<int> inp;

bool isWashable(int len) {
    // last element of washOrder is to washed first
    // after washing, popback()
    vector<int> washOrder(inp.begin(), inp.begin() + len);
    sort(washOrder.rbegin(), washOrder.rend());
    
    // soapy stacks, new stack will be pushback(), empty left stack will be popfront()
    deque<vector<int>> dq;

    // process plates in order on input
    for (int i = 0; i < len; i++) {
        // bs and find first stack where inp plate is just larger than top of stack
        int l = 0, r = dq.size() - 1;
        while (l < r) {
            int mid = (l + r) / 2;

            if (dq[mid].back() > inp[i]) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        // place current plate on appropriate stack
        if (dq.size() == 0 || inp[i] > dq[r].back()) {
            // create new stack on right
            dq.push_back({inp[i]});
        } else {
            // add plate to binary searched stack
            dq[r].push_back(inp[i]);
        }

        // wash as many plates as possible according to washOrder
        while (!dq.empty() && washOrder.back() == dq[0].back()) {
            washOrder.pop_back();
            dq[0].pop_back();
            if (dq[0].empty()) {
                dq.pop_front();
            }
        }
    }

    return dq.empty();
}

void testcase() {
    cin >> N;
    inp.resize(N);
    for (auto &i: inp) cin >> i;

    // bs on length of prefix
    int l = 1, r = N;
    while (l < r) {
        int mid = (l + r + 1) / 2;
        if (isWashable(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    
    cout << r;
}

int32_t main() {
    freopen("dishes.in", "r", stdin);
    freopen("dishes.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int tc = 1;
    // cin >> tc;
    for (int i = 1; i <= tc; i++) {
        // cout << "Case #" << i << ": ";
        testcase();
    }
    return 0;
}
