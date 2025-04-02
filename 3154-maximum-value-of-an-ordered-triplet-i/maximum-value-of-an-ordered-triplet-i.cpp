class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<long long> maxr(n, nums[n-1]);
        for(int i = n - 2; i >= 0; i--){
            maxr[i] = max((long long)nums[i], maxr[i+1]);
        }

        long long maxi = nums[0];
        long long ans = 0;
        for(int i = 2; i < n; i++){
            maxi = max(maxi, (long long)nums[i-2]);
            long long cur = (maxi - nums[i-1])*maxr[i];
            ans = max(ans, cur);
        }
        return ans;
    }
};