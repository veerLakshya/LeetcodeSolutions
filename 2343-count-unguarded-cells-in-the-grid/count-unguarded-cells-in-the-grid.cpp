class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards,
                       vector<vector<int>>& walls) {
        vector<vector<int>> mat(m, vector<int>(n, 0));
        for (auto i : walls) {
            mat[i[0]][i[1]] = 2;
        }
        for (auto i : guards) {
            mat[i[0]][i[1]] = 3;
        }
        for (auto x : guards) {
            int r = x[0], c = x[1];
            for (int i = r - 1; i >= 0; i--) {
                if (mat[i][c] == 2)
                    break;
                if (mat[i][c] == 3)
                    break;
                mat[i][c] = 1;
            }
            for (int i = r + 1; i < m; i++) {
                if (mat[i][c] == 2)
                    break;
                if (mat[i][c] == 3)
                    break;
                mat[i][c] = 1;
            }
            for (int j = c - 1; j >= 0; j--) {
                if (mat[r][j] == 2)
                    break;
                if (mat[r][j] == 3)
                    break;
                mat[r][j] = 1;
            }
            for (int j = c + 1; j < n; j++) {
                if (mat[r][j] == 2)
                    break;
                if (mat[r][j] == 3)
                    break;
                mat[r][j] = 1;
            }
        }
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0)
                    cnt++;
            }
        }
        return cnt;
    }
};