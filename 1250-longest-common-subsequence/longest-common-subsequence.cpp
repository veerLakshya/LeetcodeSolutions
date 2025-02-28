class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n + 1, vector<int> (m+1, -1));

        function<int(int, int)> h = [&](int i, int j) -> int {
            if (i < 0 || j < 0) return 0;
            if(dp[i][j] != -1) return dp[i][j];
            int cur = 0;
            if (text1[i] == text2[j])
                cur = 1 + h(i - 1, j - 1);
            else
                cur = max(h(i - 1, j), h(i, j - 1));
            return dp[i][j] = cur;
        };
        return h(n - 1, m - 1);
    }
};