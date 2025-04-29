class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long n = nums.size(), ans = 0, r = 0, cnt = 0;
        // ans += n*(n+1)/2;
        long long maxi = *max_element(nums.begin(), nums.end());
        for(int i = 0; i < n; i++){
            while(r < n && cnt < k){
                cnt += (nums[r++] == maxi);
            }
            if(cnt == k) ans += n-r+1;
            cnt -= nums[i] == maxi;
        }
        return ans;
    }
};