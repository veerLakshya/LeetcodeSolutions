class Solution {
public:
    long long power(long long a, long long b, long long mod){
        a %= mod;
        long long res = 1;
        while(b > 0){
            if(b&1) res = (res*a) % mod;
            a = a * a % mod;
            b >>= 1;
        }
        return res;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<int> depth(n + 1, 0);
        vector<vector<int>> adj(n + 1);
        for (auto i : edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        function<void(int, int, int)> dfs = [&](int cur, int par, int d) {
            depth[cur] = d;
            for (auto nbr : adj[cur]) {
                if (nbr != par) {
                    dfs(nbr, cur, d + 1);
                }
            }
        };
        dfs(1, 0, 0);
        long long ans = 0, MOD = 1e9 + 7;
        long long maxD = *max_element(depth.begin(), depth.end());
        // lets say maxD is m then no. of ways to allocate odd sum to edges is
        // mC1 + mC3 + mC5 + ..... till r less than M, which is equal to 2^(m-1)

        // we are choosing 1, 3, 5, 7.... as # of ones in path, since odd num of
        // 1s since then rest of the allocation wouldnt matter and total sum of
        // path will be odd

        ans = power(2, maxD-1, MOD);

        return ans;
    }
};