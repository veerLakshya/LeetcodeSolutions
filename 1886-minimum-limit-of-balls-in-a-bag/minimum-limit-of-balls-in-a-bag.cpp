class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        long long n = nums.size();
        long long low = 1, high = *max_element(nums.begin(),nums.end()), ans = 1;
        while(low <= high){
            long long mid = low + (high - low)/ 2;
            long long cnt = 0;
            for(int i = 0; i < n; i++){
                cnt += (nums[i] - 1) / mid;
            }
            if(cnt <= maxOperations){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};