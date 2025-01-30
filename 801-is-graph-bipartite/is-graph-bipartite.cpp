class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, -1);
        bool is_bipartite = true;
        queue<int> q;
        for (int st = 0; st < n; ++st) {
            if (vis[st] == -1) {
                q.push(st);
                vis[st] = 0;
                while (!q.empty()) {
                    int v = q.front();
                    q.pop();
                    for (int u : graph[v]) {
                        if (vis[u] == -1) {
                            vis[u] = vis[v] ^ 1;
                            q.push(u);
                        } else {
                            is_bipartite &= (vis[u] != vis[v]);
                            if(!is_bipartite)return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};