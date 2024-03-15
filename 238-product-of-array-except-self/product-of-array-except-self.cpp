class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n= nums.size();
        vector <int> ans(n);
        int product = 1;
        int count0=0;
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=0)product*=nums[i];
            else count0++;
        }
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=0){
                if(count0!=0)ans[i]=0;
                else ans[i]=product/nums[i];
            }
            else{
                if(count0-1!=0)ans[i]=0;
                else ans[i]=product;
            }
        }
        return ans;
        
    }
};