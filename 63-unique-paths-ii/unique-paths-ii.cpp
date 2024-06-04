class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& v) {
        int m = v.size(), n = v[0].size();

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                v[i][j] = 1 - v[i][j];
                if(i + j > 0 && v[i][j])
                    v[i][j] = (i > 0 ? v[i - 1][j] : 0) + (j > 0 ? v[i][j - 1] : 0);
            }
        }
        return v[m - 1][n - 1];
    }
};