class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> dx = {0, 0, -1, 1}, dy = {1, -1, 0, 0};
        vector<vector<int>> islandId(n, vector<int>(n, 0));
        unordered_map<int, int> islandSize;
        int islandIndex = 2, maxSize = 0;

        // DFS function to compute island size
        auto dfs = [&](int i, int j, int id, auto&& self) -> int {
            if (i < 0 || j < 0 || i >= n || j >= n || grid[i][j] != 1) return 0;
            grid[i][j] = id;
            int size = 1;
            for (int k = 0; k < 4; k++) {
                size += self(i + dx[k], j + dy[k], id, self);
            }
            return size;
        };

        // Step 1: Identify all islands and their sizes
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int size = dfs(i, j, islandIndex, dfs);
                    islandSize[islandIndex++] = size;
                    maxSize = max(maxSize, size);
                }
            }
        }

        // Step 2: Check every `0` cell and try merging its adjacent islands
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int> neighbors;
                    int newSize = 1;  // Flip `0` to `1`
                    for (int k = 0; k < 4; k++) {
                        int x = i + dx[k], y = j + dy[k];
                        if (x >= 0 && y >= 0 && x < n && y < n && grid[x][y] > 1) {
                            neighbors.insert(grid[x][y]);  // Add unique island indices
                        }
                    }
                    for (int id : neighbors) {
                        newSize += islandSize[id];  // Sum up sizes of connected islands
                    }
                    maxSize = max(maxSize, newSize);
                }
            }
        }

        return maxSize;
    }
};
