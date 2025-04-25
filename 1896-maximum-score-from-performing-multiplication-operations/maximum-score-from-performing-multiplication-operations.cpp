class Solution {
public:
    int dp[301][10005];
    // 0 1 2 3 4 5 6 8
    // | | . . . . | |
    // . . . . i . . .
    // . . b . . e . .
    // b = 2
    // e = i + b - 1
    // used 2
    long long int h(int ind, int used, auto& a, auto& b){
        if(ind == b.size()) return 0;
        if(dp[ind][used] != -1) return dp[ind][used];
        int beg = used;
        int takenfromend = ind - beg;
        int end = a.size() - 1 - takenfromend;
        int op1 = a[beg]*b[ind] + h(ind + 1, used + 1, a, b); 
        int op2 = a[end]*b[ind] + h(ind + 1, used, a, b);
        return dp[ind][used] = max(op1, op2); 
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        memset(dp, -1, sizeof dp);
        return h(0, 0, nums, multipliers);
    }
};