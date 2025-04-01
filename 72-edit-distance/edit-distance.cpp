class Solution {
public:
    int h(int i, int j, string& s, string& t, auto& dp){
        if(j < 0) return i+1;
        if(i < 0) return j+1;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == t[j]) return dp[i][j] =  h(i-1,j-1,s,t, dp);
        return dp[i][j] = 1 + min({h(i-1,j,s,t, dp), h(i-1,j-1,s,t, dp), h(i,j-1,s,t, dp)});
    }
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n, vector<int> (m,-1));
        return h(n-1,m-1,word1,word2, dp);
    }
};