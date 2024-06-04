class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1)return 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(obstacleGrid[i][j]==1)obstacleGrid[i][j]=-1;
            }
        }
        obstacleGrid[0][0]=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0&&j==0)continue;
                else if(obstacleGrid[i][j]==-1){
                    obstacleGrid[i][j]=0;
                }
                else{
                    if(i>0)obstacleGrid[i][j]+= obstacleGrid[i-1][j];
                    if(j>0)obstacleGrid[i][j]+= obstacleGrid[i][j-1];
                }
            }
        }
        return obstacleGrid[m-1][n-1];
        
    }
};