class Solution {
    vector<vector<int>> states, adj;
    vector<vector<int>> memo;
    int MOD = 1e9 + 7;
    bool good(const vector<int>& a, const vector<int>& b) {
        for (int i = 0; i < a.size(); i++) if (a[i] == b[i]) return false;
        return true;
    }
    void gen(int m) {
        vector<int> cur(m);
        function<void(int)> dfs = [&](int i) {
            if (i == m) { states.push_back(cur); return; }
            for (int c = 0; c < 3; c++) {
                if (i && cur[i-1] == c) continue;
                cur[i] = c;
                dfs(i+1);
            }
        };
        dfs(0);
    }
    int dfs2(int r, int p, int n) {
        if (r == n) return 1;
        int &res = memo[r][p];
        if (res != -1) return res;
        long long ans = 0;
        if (p == adj.size()) {
            for (int j = 0; j < states.size(); j++)
                ans = (ans + dfs2(r+1, j, n)) % MOD;
        } else {
            for (int j : adj[p])
                ans = (ans + dfs2(r+1, j, n)) % MOD;
        }
        return res = ans;
    }

public:
    int colorTheGrid(int m, int n) {
        gen(m);
        int K = states.size();
        adj.assign(K, {});
        for (int i = 0; i < K; i++)
            for (int j = 0; j < K; j++)
                if (good(states[i], states[j]))
                    adj[i].push_back(j);
        memo.assign(n, vector<int>(K+1, -1));
        return dfs2(0, K, n);
    }
};