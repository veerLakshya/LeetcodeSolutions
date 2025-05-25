class Solution {
public:
    long long minCuttingCost(int n, int m, int k) {
        if(n <=k && m <= k) return 0;
        long long ans = 0;
        ans += max(0ll , (long long)k*(n-k));
        ans += max(0ll, (long long)k*(m-k));
        return ans;
    }
};