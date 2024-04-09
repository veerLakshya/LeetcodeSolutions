class Solution {
public:
    int findMin(vector<int>& nums) {
        // int low =0;
        // int high = nums.size()-1;
        // int ans
        // while(low<=high)
        int ans = nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1]){
                ans=nums[i];
                return ans;
            }
        }
        return ans;
        
    }
};