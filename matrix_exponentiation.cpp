vector<vector<int>> mat_mul(vector<vector<int>> a, vector<vector<int>> b) {
    vector<vector<int>> res(a.size(), vector<int>(b[0].size()));
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b[0].size(); j++) {
            for (int k = 0; k < a[0].size(); k++) {
                res[i][j] += a[i][k] * b[k][j];
                res[i][j] %= MOD;
            }
        }
    }
    return res;
}

vector<vector<int>> mat_expo(vector<vector<int>> a, int b) {
    vector<vector<int>> res(a.size(), vector<int>(a.size()));
    for (int i = 0; i < a.size(); i++) res[i][i] = 1;

    while (b) {
        if (b & 1) {
            res = mat_mul(res, a);
        }
        a = mat_mul(a, a);
        b >>= 1;
    }

    return res;
}

// vector<vector<int>> ans = mat_mul(states, mat_expo(transition, power));
// transition[i][j] = how many times does prev state i contibute to next state j
