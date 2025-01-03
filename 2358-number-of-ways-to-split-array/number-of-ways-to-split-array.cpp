class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long ans =  0, n = nums.size();
        vector<long long> pre(n+1, 0);
        for(int i = 1; i <= n; i++)
            pre[i] = pre[i-1] + nums[i-1];
        for(auto i: pre) cout << i << " ";
        cout << endl;
        for(int i = 1; i < n; i++) ans += (pre[i] >= pre[n] - pre[i]);
        return ans;
    }
};