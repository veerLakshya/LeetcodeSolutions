class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int pos = 0, neg = 0;
        int left = 0, right = n - 1;
        while(left <= right){
            int mid = (left+right) / 2;
            if(nums[mid] > 0){
                pos = (n - mid);
                right = mid - 1;
            }
            else left = mid + 1;
        }
        left = 0, right = n - 1;
        while(left <= right){
            int mid = (left+right) / 2;
            if(nums[mid] < 0){
                neg = mid+1;
                left = mid+1;
            }
            else right = mid - 1;
        }
        return max(neg, pos);
    }
};