class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size(), ans = 0;
        vector<int> l(n, 1), r(n, 1);
        for(int i = 1; i < n; i++) l[i] = 1 + (ratings[i] > ratings[i-1] ? l[i-1] : 0);
        for(int i = n - 2; i >= 0; i--) r[i] = 1 + (ratings[i] > ratings[i+1] ? r[i+1]: 0);
        for(int i = 0; i < n; i++) ans += max(l[i], r[i]);
        return ans;
    }
};