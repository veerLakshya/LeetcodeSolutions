class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long n = nums.size();
        vector<long long> pre(n+1, 0);
        for(int i = 1; i <= n; i++) pre[i] = pre[i-1] + nums[i - 1];
        long long rem = pre[n] % p;
        if(!rem) return 0;
        else if (pre[n] < p) return -1;

        unordered_map <long long, long long> mp;
        long long ans = 1e9;
        for(int i = 0; i <= n; i++){
            long long cur = pre[i] % p;
            long long req = (cur - rem + p) % p;
            if(mp.find(req) != mp.end()){
                ans = min(ans, i - mp[req]);
            }
            mp[cur] = i;
        }
        if(ans == n) ans = -1;
        return ans;
    }
};