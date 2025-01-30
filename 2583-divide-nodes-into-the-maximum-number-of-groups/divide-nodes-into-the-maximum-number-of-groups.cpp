class Solution {
public:
    // Function to check if the graph is bipartite
    bool isBipartite(vector<vector<int>>& graph, vector<int>& color) {
        int n = graph.size();
        for (int st = 0; st < n; ++st) {
            if (color[st] == -1) { // Unvisited node
                queue<int> q;
                q.push(st);
                color[st] = 0; // Start coloring
                
                while (!q.empty()) {
                    int v = q.front();
                    q.pop();
                    for (int u : graph[v]) {
                        if (color[u] == -1) {
                            color[u] = color[v] ^ 1; // Alternate color
                            q.push(u);
                        } 
                        else if (color[u] == color[v]) return false; // Odd cycle detected
                    }
                }
            }
        }
        return true;
    }

    // BFS to find max layered depth starting from 'start' node
    int maxLayeredBFS(int start, vector<vector<int>>& edj) {
        queue<int> q;
        vector<int> level(edj.size(), -1);
        q.push(start);
        level[start] = 1;
        int maxLayers = 1;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int neighbor : edj[node]) {
                if (level[neighbor] == -1) {
                    level[neighbor] = level[node] + 1;
                    maxLayers = max(maxLayers, level[neighbor]);
                    q.push(neighbor);
                }
            }
        }
        return maxLayers;
    }

    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> edj(n);
        for (auto& edge : edges) {
            int x = edge[0] - 1, y = edge[1] - 1;
            edj[x].push_back(y);
            edj[y].push_back(x);
        }
        
        vector<int> color(n, -1);
        if (!isBipartite(edj, color)) return -1; // Check if the graph contains an odd-length cycle

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

                // Find the best depth using layered BFS
                int maxDepth = 0;
                for (int node : component) {
                    maxDepth = max(maxDepth, maxLayeredBFS(node, edj));
                }
                maxOverallDepth += maxDepth;
            }
        }

        return maxOverallDepth;
    }
};