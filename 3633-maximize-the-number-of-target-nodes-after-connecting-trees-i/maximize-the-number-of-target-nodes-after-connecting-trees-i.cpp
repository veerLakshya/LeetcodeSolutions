class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size() + 1, m = edges2.size() + 1;
        vector<int> ans(n, 1);
        if(k == 0) return ans;
        vector<int> nodes(m, 0);

        vector<vector<int>> adj1(n), adj2(m);
        for(auto i: edges1){
            adj1[i[0]].push_back(i[1]);
            adj1[i[1]].push_back(i[0]);
        }
        for(auto i: edges2){
            adj2[i[0]].push_back(i[1]);
            adj2[i[1]].push_back(i[0]);
        }
        // auto h = [&](int start, int roads){
            
        // }
        function<int(int, int, int, int)> dfs = [&](int cur, int par, int d, int tree){
            if(d <= 0) return 1;
            int cnt = 1;
            for(auto nbr: (tree == 1 ? adj1[cur] : adj2[cur])){
                if(nbr != par){
                    cnt += dfs(nbr, cur, d - 1, tree);
                }
            }
            return cnt;
        };
        for(int i = 0; i < m; i++){
            nodes[i] = dfs(i, -1, k - 1, 2);
        }
        int maxi = *max_element(nodes.begin(), nodes.end());
        for(int i = 0; i < n; i++){
            ans[i] = dfs(i, -1, k, 1) + maxi;
        }
        return ans;
    }
};