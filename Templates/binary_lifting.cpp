const int LOG = log2(k) + 1;
vector<vector<int>> up(n + 1, vector<int>(LOG));

// set parents
for (int v = 0; v <= n; v++) {
    up[v][0] = mapping[v];
}
// compute other ancestors
for (int j = 1; j < LOG; j++) {
    for (int v = 0; v <= n; v++) {
        up[v][j] = up[up[v][j - 1]][j - 1];
    }
}

// get k'th ancestor of v
for (int j = 0; j < LOG; j++) {
    if (k & (1 << j)) {
        v = up[v][j];
    }
}
cout << v << " ";
