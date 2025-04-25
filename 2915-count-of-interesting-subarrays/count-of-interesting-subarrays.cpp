class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        long long ans = 0, n = nums.size();
        for(auto &i: nums) i = (i%modulo == k);
        vector<int> pre(n + 1, 0);
        for(int i = 1; i <= n; i++) pre[i] = pre[i-1] + nums[i-1];
        for(auto i: nums) cout << i << " ";
        cout << endl;
        for(auto i: pre) cout << i << " ";
        map<int,int> mp;
        mp[pre[0]] = 1;
        for(int i = 1; i <= n; i++){
            // how many indices such that (pre[i] - pre[j])%mod == k
            // pre[i]%mod - pre[j]%mod 
            ans += mp[(pre[i]-k)%modulo];
            mp[pre[i]%modulo]++;
        }
        return ans;
    }
};