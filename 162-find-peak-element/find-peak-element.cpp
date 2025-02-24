class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size()-1, n = nums.size();
        while(l <= r){
            int mid = (l + r) / 2;
            if((mid == 0 || nums[mid-1] < nums[mid] ) && 
            (mid == n-1 || nums[mid+1] < nums[mid])) return mid;
            else if(mid > 0 && nums[mid-1] > nums[mid])
            r = mid - 1;
            else l = mid + 1;
        }
        return -1;
    }
};