class Solution {
public:
    // Function to check if the graph is bipartite
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, -1);
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
                        } 
                        else if (vis[u] == vis[v]) return false; // Odd cycle detected
                    }
                }
            }
        }
        return true;
    }

    // BFS to find the maximum depth starting from a given node
    int bfsMaxDepth(int start, vector<vector<int>>& edj) {
        queue<int> q;
        unordered_map<int, int> depth;
        q.push(start);
        depth[start] = 1;
        int maxDepth = 1;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int neighbor : edj[node]) {
                if (depth.find(neighbor) == depth.end()) {
                    depth[neighbor] = depth[node] + 1;
                    maxDepth = max(maxDepth, depth[neighbor]);
                    q.push(neighbor);
                }
            }
        }
        return maxDepth;
    }

    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> edj(n);
        for (auto i : edges) {
            int x = i[0] - 1; 
            int y = i[1] - 1;
            edj[x].push_back(y);
            edj[y].push_back(x);
        }
        
        if (!isBipartite(edj)) return -1; // Check if the graph contains an odd-length cycle

        int maxOverallDepth = 0;
        vector<bool> visited(n, false);

        // Find the maximum depth in each connected component
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                queue<int> q;
                vector<int> component;
                
                q.push(i);
                visited[i] = true;
                
                // BFS to find all nodes in this connected component
                while (!q.empty()) {
                    int node = q.front();
                    q.pop();
                    component.push_back(node);
                    for (int neighbor : edj[node]) {
                        if (!visited[neighbor]) {
                            visited[neighbor] = true;
                            q.push(neighbor);
                        }
                    }
                }

                // Find the best depth starting from any node in this component
                int maxDepth = 0;
                for (int node : component) {
                    maxDepth = max(maxDepth, bfsMaxDepth(node, edj));
                }
                maxOverallDepth += maxDepth;
            }
        }

        return maxOverallDepth;
    }
};
