class Solution {
public:
    long long h(int i, auto& a, auto& dp){
        if(i >= a.size()) return 0;
        if(dp[i] != -1) return dp[i];
        long long op1 = a[i][0] + h(i + 1 + a[i][1], a, dp);
        long long op2 = h(i + 1, a, dp);
        return dp[i] = max(op1, op2);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n+1, -1);
        return h(0, questions, dp);  
    }
};