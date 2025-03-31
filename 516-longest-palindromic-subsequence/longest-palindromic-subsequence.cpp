class Solution {
public:
    int ans = 0;
    int h(int i, int j, string& s, vector<vector<int>>& dp){
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == s[j]) {
            dp[i][j] = (i ==j ? 1 : 2);
            dp[i][j] += h(i+1, j-1, s, dp);
        }
        else dp[i][j] = max(h(i+1, j, s, dp), h(i, j - 1, s, dp));
        ans = max(ans, dp[i][j]);
        return dp[i][j];
    }
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        h(0,n-1, s, dp);
        return ans;
    }
};