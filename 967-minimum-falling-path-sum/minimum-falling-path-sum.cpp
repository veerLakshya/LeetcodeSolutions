class Solution {
public:
    int minimum(int a,int b,int c){
        return min(a, min(b, c));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 1)return *min_element(matrix[0].begin(),matrix[0].end());
        
        for(int i = 1;i<n;i++){
            for(int j=0;j<n;j++){
                int left = (j>0) ? matrix[i-1][j-1] : INT_MAX;
                int mid = matrix[i-1][j];
                int right = (j<n-1) ? matrix[i-1][j+1] : INT_MAX;
                matrix[i][j] += minimum(left,mid,right);
            }
        }
        return *min_element(matrix[n-1].begin(),matrix[n-1].end());
    }
};