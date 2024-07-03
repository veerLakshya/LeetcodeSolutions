class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        if(n<=4){
            return 0;
        }
        for(auto i: nums)cout<<i<<" ";
        return min(nums[n-1]-nums[3],min(nums[n-2]-nums[2],min(nums[n-3]-nums[1],nums[n-4]-nums[0])));
    
    }
};