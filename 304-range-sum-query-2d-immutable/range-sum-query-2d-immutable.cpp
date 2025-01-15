class NumMatrix {
public:
    vector<vector<int>> pre;
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> a(n + 1, vector<int> (m + 1,0));

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                a[i][j] = matrix[i-1][j-1] + a[i-1][j] + a[i][j-1] - a[i-1][j-1];
            }
        }
        pre = a;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = 0;
        int total = pre[row2 + 1][col2 + 1];
        
        total += pre[row1][col1];
        total -= pre[row1][col2 + 1];
        total -= pre[row2+1][col1];

        return total;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */