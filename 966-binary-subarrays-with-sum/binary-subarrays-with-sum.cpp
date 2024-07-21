class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int ans = 0, right = 0, left = 0, cur = 0;
        while(left < n){
            int sum = nums[left];
            if(sum == goal)ans++;
            for(int i = left + 1; i < n; i++){
                sum+=nums[i];
                if(sum == goal)ans++;
            }
            left++;
        }
        return ans;
    }
};