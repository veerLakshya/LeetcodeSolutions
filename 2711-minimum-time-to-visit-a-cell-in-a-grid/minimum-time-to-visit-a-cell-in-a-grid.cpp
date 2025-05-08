class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        if (grid[0][1] > 1 && grid[1][0] > 1)
            return -1;
        vector<int> dx = {0, 0, -1, 1}, dy = {1, -1, 0, 0};
        vector<vector<int>> vis(n, vector<int>(m, -1));
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> q;
        q.push({0, 0, 0});
        vis[0][0] = 0;
        while (q.size()) {
            auto cur = q.top();
            q.pop();
            if (cur[1] == n - 1 && cur[2] == m - 1)
                return cur[0];
            for (int i = 0; i < 4; i++) {
                int x = cur[1] + dx[i];
                int y = cur[2] + dy[i];
                if (x >= n || x < 0 || y < 0 || y >= m || vis[x][y] != -1)
                    continue;

                if (grid[x][y] <= cur[0] + 1) {
                    // if next cell ka T less than cur cell time then we move to
                    // next with curT + 1
                    vis[x][y] = cur[0] + 1;
                } else {
                    // if next cell ka T and next cell ka T have same parity
                    // then we do max of both + 1 as we will have to do round
                    // trip around other cells which will be even time spent and
                    // then 1 time to move to the next cell
                    vis[x][y] = grid[x][y];
                    if ((grid[x][y] - cur[0]) % 2 == 0)
                        vis[x][y]++;
                }
                q.push({vis[x][y], x, y});
            }
        }
        return -1;
    }
};