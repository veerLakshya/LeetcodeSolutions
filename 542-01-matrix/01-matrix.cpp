class Solution {
public:
    vector<int> DIR = {0, 1, 0, -1, 0};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++)
                if (mat[i][j] == 0) q.push({i, j});
                else mat[i][j] = -1; // Marked as not processed yet!
        }

        while (!q.empty()) {
            auto [i, j] = q.front(); q.pop();
            for (int k = 0; k < 4; k++) {
                int x = i + DIR[k], y = j + DIR[k+1];
                if (x < 0 || x == m || y < 0 || y == n || mat[x][y] != -1) continue;
                mat[x][y] = mat[i][j] + 1;
                q.push({x, y});
            }
        }
        
        return mat;
    }
};
