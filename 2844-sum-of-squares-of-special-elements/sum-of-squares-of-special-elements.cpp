class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        long long int ans=0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(n%(i+1)==0){
            ans+= (nums[i]*nums[i]);
            cout<<i<<" ";
            } 
        }
        cout<<endl;
        return ans;
        
    }
};