class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, -1);
        auto bfs = [&](int cur, int col, auto self) -> bool{
            vis[cur] = col;
            bool ans = true;
            for(auto nbr: graph[cur]){
                if(vis[nbr] == -1) {
                    bool f = self(nbr,(col == 0 ? 1 : 0), self);
                    if(!f) return false;
                }
                else if(vis[nbr] == col) return false;
            }
            return true;
        };
        bool ans = true;
        for(int i = 0; i < n; i++){
            if(vis[i] == -1){
                bool cur = bfs(i,0, bfs);
                ans &= cur;
            }
        }
       return ans;
    }
};