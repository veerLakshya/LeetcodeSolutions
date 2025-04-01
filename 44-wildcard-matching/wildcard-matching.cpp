class Solution {
public:
    bool h(int i, int j, string& s, string& p, vector<vector<int>>& dp){
        if(i < 0 && j < 0) return 1;
        if(j < 0) return false;
        if(i < 0){
            for(int k = 0; k <= j; k++) if(p[k] != '*') return false;
            return true;
        }
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == p[j] || p[j] == '?') return dp[i][j] = h(i-1, j-1, s, p, dp);
        if(p[j] == '*') return dp[i][j] = h(i, j-1, s, p, dp) || h(i-1,j,s,p, dp);

        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<int>> dp(n, vector<int> (m,-1));
        return h(n-1, m-1, s, p, dp);
    }
};