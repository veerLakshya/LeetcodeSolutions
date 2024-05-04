class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            int low = 0;
            int high = m-1;
            int add=0;
            while(low<=high){
                int mid=(low+high)/2;
                if(grid[i][mid]<0){
                    add= m-mid;
                    high=mid-1;
                }
                else
                    low=mid+1;
            }
            // cout<<"[add"<<"="<<add<<" ans="<<ans<<" ]";
            ans=ans +add;
        }
        return ans;
    }
};