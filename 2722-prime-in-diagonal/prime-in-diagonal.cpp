class Solution {
public:
    bool isPrime(int n)
    {
        // Corner case
        if (n <= 1)
            return false;
    
        // Check from 2 to n-1
        for (int i = 2; i <= n / 2; i++)
            if (n % i == 0)
                return false;
    
        return true;
    }
    int diagonalPrime(vector<vector<int>>& nums) {
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i][i]>ans)
            if(isPrime(nums[i][i])){
                ans=max(ans,nums[i][i]);
            }
            if(nums[i][n-i-1]>ans)
            if(isPrime(nums[i][n-i-1])){
                ans=max(ans,nums[i][n-i-1]);
            }
        }
        return ans;
    }
};