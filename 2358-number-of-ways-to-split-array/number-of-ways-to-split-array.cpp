class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long ans =  0, n = nums.size();
        vector<long long> pre(n+1, 0), suf(n+1, 0);
        for(int i = 1; i <= n; i++)
            pre[i] = pre[i-1] + nums[i-1];
        for(int i = n ; i > 0; i--)
            suf[i - 1] = suf[i] + nums[i - 1];
        // for(auto i: pre) cout << i << " ";
        // cout << endl;
        // for(auto i: suf) cout << i << " ";
        for(int i = 1; i < n ; i++) ans += (pre[i] >= suf[i]);
        return ans;
    }
};