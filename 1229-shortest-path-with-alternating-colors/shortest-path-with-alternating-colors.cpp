class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto i: redEdges){
            adj[i[0]].push_back({i[1],1});
        }
        for(auto i: blueEdges){
            adj[i[0]].push_back({i[1],0});
        }
        vector<int> ans(n , 1e9);
        vector<vector<int>> vis(n, vector<int> (2, 0));
        queue<array<int,3>> q;
        q.push({0,0,-1});
        while(q.size()){
            auto [node, dis, lastused] = q.front();
            ans[node] = min(ans[node], dis);
            q.pop();
            for(auto [nbr, edge]: adj[node]){
                if(vis[nbr][edge])continue;
                if(edge == lastused) continue;
                q.push({nbr, dis + 1, edge});
                vis[nbr][edge] = 1;
            }
        }
        for(int i = 0; i < n; i++) if(ans[i] == 1e9) ans[i] = -1;
        return ans;
    }
};