class Solution {
public:
    bool isvalid(int a, int b) {
        int num = a*10 + b;
        return num >= 10 && num < 27;
    }
    int dp[101];
    int h(int i, string& s) {
        int n = s.size();
        if (i >= n) return 1;
        if(dp[i] != -1) return dp[i];
        if(s[i] == '0') return 0;
        int ways = h(i + 1, s);
        if (i + 1 < n && isvalid((int)(s[i] - '0'), (int)(s[i + 1] - '0')))
            ways += h(i + 2, s);
        return dp[i] = ways;
    }
    int numDecodings(string s) {
        if (s[0] == '0') return 0;
        memset(dp, -1, sizeof dp);
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == '0'){
                if(s[i - 1] == '1' || s[i - 1] == '2') continue;
                else return 0;
            }
        }
        return h(0, s);
    }
};