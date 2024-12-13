class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int> (n,-1));

        auto f = [&](int i, int j, auto self)-> int{
            if(i == n-1) return triangle[i][j];
            if(dp[i][j] != -1) return dp[i][j];
            int d = triangle[i][j] + self(i+1, j, self);
            int dg = triangle[i][j] + self(i+1, j+1, self);

            return dp[i][j] = min(d,dg);
        };

        return f(0, 0, f);
    }
};