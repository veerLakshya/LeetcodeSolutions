class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long totala = (long long)0, n = grid[0].size(), ans = (long long)LONG_LONG_MAX;
        totala = accumulate(grid[0].begin(), grid[0].end(), (long long)0);
        long long cura = 0, curb = 0;
        for(long long i = 0; i < n; i++){
            cura += grid[0][i];
            long long above = totala - cura;
            ans = min(ans, max(above, curb));
            curb += grid[1][i];
        }
        return ans;
    }
};