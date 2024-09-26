class Solution {
public:
    int n,m;
    int helper(string& s1, string& s2, int i, int j, vector<vector<int>>& dp){
        if(i == s1.size() || j == s2.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        if(s1[i] == s2[j]) 
            return dp[i][j] = 1 + helper(s1, s2, i+1, j+1, dp);

        int op1 = helper(s1, s2, i + 1, j, dp);
        int op2 = helper(s1, s2, i, j + 1, dp);
        return dp[i][j] = max(op1, op2);
    }
    int longestCommonSubsequence(string text1, string text2) {
        n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n + 1, vector<int> (m+1,-1));
        return helper(text1, text2, 0, 0, dp);
    }
};