class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> sum(n+1, vector<int>(m+1, 0));
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                sum[i][j] = matrix[i-1][j-1] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; i++){            // r1 for submatrix
            for(int j = i; j <= n; j++){        // r2 for submatrix
                unordered_map<int,int> mp;
                mp[0] = 1;
                for(int k = 1; k <= m; k++){    // cur col for submatrix
                    int cursum = sum[j][k] - sum[i-1][k];
                    if(mp.find(cursum - target)!=mp.end()) ans += mp[cursum- target];
                    mp[cursum]++;
                }
            }
        }
        return ans;
    }
};