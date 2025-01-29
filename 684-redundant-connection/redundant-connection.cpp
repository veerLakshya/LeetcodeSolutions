class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int N = edges.size();
        vector<vector<int>> adjList(N);
        vector<bool> visited(N, false);
        
        auto isConnected = [&](int src, int target, auto self)-> bool {
            visited[src] = true;
            if (src == target)return true;
            int isFound = false;
            for (int adj : adjList[src]) {
                if (!visited[adj]) isFound = isFound || self(adj, target, self);
            }
            return isFound;
        };

        for (auto edge : edges) {
            if (isConnected(edge[0] - 1, edge[1] - 1, isConnected)) {
                return edge;
            }
            adjList[edge[0] - 1].push_back(edge[1] - 1);
            adjList[edge[1] - 1].push_back(edge[0] - 1);
            vector<bool> vis(N, false);
            visited = vis;
        }
        return {};
    }
};