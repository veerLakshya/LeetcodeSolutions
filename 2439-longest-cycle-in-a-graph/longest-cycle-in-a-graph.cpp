class Solution {
public:
    vector<int> adj[100069];
    int vis[100069], h[100069];
    int n, ans = -1;
    void dfs(int node, int d, auto& adj){
        vis[node] = 1;
        h[node] = d;
        for(auto nbr: adj[node]){
            if(!vis[nbr]) dfs(nbr, d + 1, adj);
            else if(vis[nbr] == 1){
                ans = max(ans, d - h[nbr] + 1);
            }
        }
        vis[node] = 2;
    }
    int longestCycle(vector<int>& edges) {
        n = edges.size();
        for(int i = 0; i < n; i++){
            if(edges[i] != -1){
                adj[i].push_back(edges[i]);
            }
        }
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                dfs(i, 1, adj);
            }
        }
        return ans;
    }
};
