class Solution {
public:
    int countArrays(vector<int>& original, vector<vector<int>>& bounds) {
        int n = original.size(), ans = INT_MAX;
        for(int i = 0 ; i < n - 1; i++){
            int diff = original[i + 1] - original[i];
            vector<int> temp = {bounds[i][0] + diff, bounds[i][1] + diff};
            vector<int> pos = {max(temp[0], bounds[i + 1][0]), min(temp[1], bounds[i+1][1])};
            bounds[i+1] = pos;
            ans = min(ans, pos[1]-pos[0] + 1);
        }
        return ans > 0 ? ans : 0;
    }
};