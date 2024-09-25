class Solution {
public:
    int jump(vector<int>& nums) {
        int res = 0, l = 0, r = 0;
        while( r < nums.size() - 1){
            int farthest = 0;
            for(int i = l; i < r + 1; i++){
                farthest = max(farthest,nums[i] + i);
            }
            l = r + 1;
            r = farthest;
            res++;
        }
        return res;
    }
};