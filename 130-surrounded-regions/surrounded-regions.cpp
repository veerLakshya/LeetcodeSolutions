class Solution {
public:
    void print(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cout << a[i][j] << " ";
            cout << endl;
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        vector<int> dx = {1, -1, 0, 0}, dy = {0, 0, -1, 1};
        vector<vector<int>> vis(m, vector<int>(n, 0));

        auto h = [&](int i, int j, auto& self) -> void {
            vis[i][j] = 1;
            for (int k = 0; k < 4; k++) {
                int x = i + dx[k];
                int y = j + dy[k];
                if (x >= 0 && y >= 0 && x < m && y < n && board[x][y] == 'O' &&
                    !vis[x][y]) {
                    self(x, y, self);
                }
            }
        };

        // Mark all 'O's on the boundary and their connected components
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O' &&
                    (i == 0 || j == 0 || i == m - 1 || j == n - 1) &&
                    !vis[i][j]) {
                    h(i, j, h);
                }
            }
        }

        // Flip the unvisited 'O's to 'X'
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O' && !vis[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};