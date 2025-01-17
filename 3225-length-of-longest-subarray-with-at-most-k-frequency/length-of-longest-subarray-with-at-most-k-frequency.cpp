class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int ans = 0, r = 0, n = nums.size();
        map<int,int> mp;
        for(int i = 0; i < n; i++){
            while(r < n){
                mp[nums[r]]++;
                if(mp[nums[r]] > k){
                    mp[nums[r]]--;
                    break;
                }
                r++;
            }
            ans = max(ans, r-i);
            mp[nums[i]]--;
        }
        return ans;
    }
};