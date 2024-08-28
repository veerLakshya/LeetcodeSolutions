class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        for(int i = 1; i < triangle.size(); i++){
            int m = triangle[i-1].size();
            for(int j = 0; j < triangle[i].size(); j++){
                triangle[i][j] += min((j>0) ? triangle[i-1][j-1] : INT_MAX, ((j<m) ? triangle[i-1][j] : INT_MAX));
            }
        }
        return *min_element(triangle[n-1].begin(),triangle[n-1].end());
    }
};