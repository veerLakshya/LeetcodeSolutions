class Solution {
public:
    int n, m;
    int dp[169][169][169];
    bool h(int i, int j, int open, auto& grid){
        if(open > 2 * min(n,m) || open < 0) return false;
        if(i == 0 && j == 0){
            if(open) return dp[i][j][open] = false;
            else return dp[i][j][open] = true;
        }
        if(dp[i][j][open] != -1) return dp[i][j][open];
        bool f = 0;
        if(i-1 >= 0){
            if(grid[i-1][j] == '(') f |= h(i-1, j, open - 1, grid);
            else f |= h(i-1, j, open + 1, grid);
            if(f) return dp[i][j][open] = true;
        }
        if(j-1 >= 0){
            if(grid[i][j-1] == '(') f |= h(i, j - 1, open - 1, grid);
            else f |= h(i, j - 1, open + 1, grid);
        }
        if(f) return dp[i][j][open] = true;
        return dp[i][j][open] = false;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        n = grid.size(), m = grid[0].size();
        memset(dp, -1, sizeof dp);
        if(grid[0][0]!= '(' || grid[n-1][m-1] != ')') return false;
        return h(n-1, m-1, 1, grid);
    }
};