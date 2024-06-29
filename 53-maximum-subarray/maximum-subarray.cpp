class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if(n==0)return n;
        if(n==1)return nums[0];
        vector<int> pre(n+1,0);
        for(int i=0;i<n;i++){
            pre[i+1]=pre[i]+nums[i];
        }
        int sum = 0, ans = INT_MIN, min_sum = 0;
        for(int i = 1; i <= n; i++){
            sum = pre[i];
            ans = max(ans, sum - min_sum);
            // cout<<"sum: "<<sum<<" min_sum: "<<min_sum<<" ans: "<<ans<<endl;
            min_sum = min(sum, min_sum);
        }
        return ans;
    }
};