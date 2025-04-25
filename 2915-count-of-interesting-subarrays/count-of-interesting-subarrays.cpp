class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        long long ans = 0, n = nums.size();
        vector<int> pre(n + 1, 0);
        for(int i = 1; i <= n; i++) pre[i] = pre[i-1] + (nums[i-1]%modulo==k);
        unordered_map<int,int> mp;
        mp[pre[0]] = 1;
        for(int i = 1; i <= n; i++){
            // how many indices such that (pre[i] - pre[j])%mod == k
            // pre[i] - pre[j] = k%mod
            ans += mp[(pre[i]-k)%modulo];
            mp[pre[i]%modulo]++;
        }
        return ans;
    }
};