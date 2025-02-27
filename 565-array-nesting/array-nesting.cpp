class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] != -1) { 
                int start = i, cnt = 0;
                while (nums[start] != -1) {
                    int temp = start;
                    start = nums[start];
                    nums[temp] = -1;
                    cnt++;
                }
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};
