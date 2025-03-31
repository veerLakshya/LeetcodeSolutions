class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size(), maxi = 0;
        vector<vector<int>> dp(n, vector<int>(n,0));

        for(int i = n - 1; i >= 0; i--){
            for(int j = i; j < n; j++){
                // if(i < j) continue;
                if(s[i] == s[j]){
                    dp[i][j] = (i == j ? 1 : 2);
                    if(i + 1 < n && j - 1 >= 0) dp[i][j] += dp[i+1][j-1];
                } 
                else{
                    if(i + 1 < n) dp[i][j] = max(dp[i][j], dp[i+1][j]);
                    if(j - 1 >= 0) dp[i][j] = max(dp[i][j], dp[i][j - 1]);
                }
            }
        }
        return dp[0][n-1];
        
    }
};