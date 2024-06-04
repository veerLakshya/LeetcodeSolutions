class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<long long>> arr(m, vector<long long>(n,1));
        // arr[0][0]=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0&&j==0)continue;
                else{
                    arr[i][j]=0;
                    if(i>0)arr[i][j]+= arr[i-1][j];
                    if(j>0)arr[i][j]+= arr[i][j-1];
                }
            }
        }
        return arr[m-1][n-1];
    }
};