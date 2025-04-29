class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size(), ans = 1;
        for(int i = 0; i < n; i++){
            map<double, int> mp; // {x,y} - y no. of points having slope as x
            for(int j = i + 1; j < n; j++){
                double m = (double)(points[i][1] - points[j][1]) / (double)(points[i][0]-points[j][0]);
                if(points[i][0]-points[j][0] == 0) mp[1e6]++;
                else mp[m]++;
            }
            for(auto i: mp){
                ans = max(ans, i.second + 1);
            }
        }
        return ans;
    }
};