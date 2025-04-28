class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long n = nums.size();
        long long ans = n*(n+1)/2;
        long long cur = 0, cnt = 0, r = 0;
        for(int l = 0; l < n; l++){
            while(r < n && cnt*cur < k){
                cnt++;
                cur += nums[r];
                r++;
            }
            if(cnt*cur >= k) ans -= n - r + 1;
            cnt--;
            cur -= nums[l];

        }
        return ans;
    }
};