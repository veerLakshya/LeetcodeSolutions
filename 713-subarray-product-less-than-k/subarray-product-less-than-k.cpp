class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size();
        int count=0;
        long long p = 1;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                p*=nums[j];
                if(p<k){
                    // cout<<p<<" ";
                    count++;
                }
                else{
                    // cout<<"|";
                    break;
                } 
            }
            p=1;
        }
        return count;
    }
};