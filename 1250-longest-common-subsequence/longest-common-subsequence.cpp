class Solution {
public:
    int n, m;
    int h(int i, int j, string& s, string& t, auto& dp){
        if(i >= n || j >= m) return dp[i][j] = 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == t[j]) dp[i][j] = 1 + h(i + 1, j + 1, s, t, dp);
        else {
            dp[i][j] = max(h(i + 1, j, s, t, dp), h(i, j + 1, s, t, dp));
        }

        return dp[i][j];
    }
    int longestCommonSubsequence(string text1, string text2) {
        n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n+1, vector<int> (m+1,-1));
        h(0, 0, text1, text2, dp);
        return dp[0][0];
    }
};