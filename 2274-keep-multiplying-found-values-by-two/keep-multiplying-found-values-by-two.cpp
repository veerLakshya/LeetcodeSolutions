class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        bool flag=1;
        while(flag){
            flag=0;
            for(int i=0;i<nums.size();i++){
                if(nums[i]==original){
                    flag=1;
                    original*=2;
                    break;
                }
            }
        }
        return original;
    }
};