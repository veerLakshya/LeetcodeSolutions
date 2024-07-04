class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size(), i = 0;
        int cnt = 0, j = 0;
        while(j<n){
            if(!nums[j]){
                k--;
            }
            if(k<0){
                if(nums[cnt]==0)k++;
                cnt++;
            }
            j++;
        }
        return j-cnt;
    }
};