class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size(), cur = 1;
        sort(nums.begin(),nums.end());
        // nums.push_back(-1e9 - 1);
        vector<int> ans;
        for(int i = 1; i < n; i++){
            if(nums[i] == nums[i-1]) cur++;
            else{
                if(cur > n /3) ans.push_back(nums[i-1]);
                cur = 1;
            }
        }
        if(cur > n /3) ans.push_back(nums.back());
        return ans;
    }
};