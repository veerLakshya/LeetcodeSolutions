class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]<=nums[n-1]){
                ans=nums[mid];
                high=mid-1;
            }
            else
            low=mid+1;
        }
        return ans;        
    }
};