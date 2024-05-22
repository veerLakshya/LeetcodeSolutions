class Solution {
public:
    bool canJump(vector<int>& nums) {
        int mindex=0;
        for(int i=0;i<nums.size();i++){
            if(i>mindex)return false;
            mindex = max(mindex ,i+nums[i]);
            cout<<mindex<<" ";
        }
        return true;
    }
};