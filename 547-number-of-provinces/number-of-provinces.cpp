class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n, 0);
        vector<vector<int>> adj(n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i!=j && isConnected[i][j]){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        auto dfs = [&](int i, auto self)->void{
            vis[i] = 1;
            for(auto nbr: adj[i]){
                if(!vis[nbr]) self(nbr, self);
            }
        };
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                ans++;
                dfs(i, dfs);
                // for(auto i: vis) cout << i << " ";
                cout << endl;
            }
        }
        return ans;
    }
};