class Solution {
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<vector<int>> f(n, vector<int>(n, -1));
        
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (words[i].size() != words[j].size()) continue;
                int diff = 0;
                for (int k = 0; k < words[i].size(); k++) {
                    if (words[i][k] != words[j][k]) diff++;
                }
                f[i][j] = f[j][i] = diff;
            }
        }

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        function<int(int, int)> h = [&](int ind, int prev) -> int {
            if (ind == n) return 0;
            if (dp[ind][prev + 1] != -1) return dp[ind][prev + 1];

            int skip = h(ind + 1, prev);
            int take = 0;
            if (prev == -1 || (groups[ind] != groups[prev] && f[ind][prev] == 1)) {
                take = 1 + h(ind + 1, ind);
            }
            return dp[ind][prev + 1] = max(skip, take);
        };

        vector<string> ans;
        function<void(int, int)> construct = [&](int ind, int prev) {
            if (ind == n) return;
            int skip = h(ind + 1, prev);
            int take = 0;
            if (prev == -1 || (groups[ind] != groups[prev] && f[ind][prev] == 1)) {
                take = 1 + h(ind + 1, ind);
            }
            if (take > skip) {
                ans.push_back(words[ind]);
                construct(ind + 1, ind);
            } else {
                construct(ind + 1, prev);
            }
        };

        h(0, -1);
        construct(0, -1);

        return ans;
    }
};
