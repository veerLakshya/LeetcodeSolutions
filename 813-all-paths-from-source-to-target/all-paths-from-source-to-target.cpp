class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        int cnt = 0;
        int n = graph.size();
        vector<int> vis(n,0);
        vector<int> cur;
        auto dfs = [&](int i, auto self)-> void{
            if(i == n-1){
                // cnt++;
                ans.push_back(cur);
                return;
            }
            vis[i] = 1;
            for(auto nbr: graph[i]){
                if(!vis[nbr]){
                    cur.push_back(nbr);
                    self(nbr, self);
                    cur.pop_back();
                } 
            }
            vis[i] = 0;
        };
        cur.push_back(0);
        dfs(0, dfs);
        // cout<<cnt;
        return ans;
    }
};