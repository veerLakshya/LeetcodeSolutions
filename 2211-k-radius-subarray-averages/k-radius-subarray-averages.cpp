class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n=nums.size();
        if(2*k +1>n){
            vector<int> v(n,-1);
            return v;
        }
        vector<int> ans(k,-1);
        long long sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(i>=2*k){
                ans.push_back(sum/(2*k  +1));  
            }
            if(i>=2*k){
                sum-=nums[i-2*k];
            }
        }
        for(int i=0;i<k;i++)ans.push_back(-1);
        return ans;
    }
};