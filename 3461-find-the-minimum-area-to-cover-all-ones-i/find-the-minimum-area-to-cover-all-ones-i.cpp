class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int width = -1, lw = INT_MAX;
        int height = -1, lh = INT_MAX;
        int cnt1=0;
        int n = grid.size(), m = grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    cnt1++;
                    width = max(j,width);
                    height =max(i,height);
                    lw = min(j,lw);
                    lh = min(i,lh);
                }
            }
        }
        return (width+1-lw)*(height+1-lh);
        
    }
};