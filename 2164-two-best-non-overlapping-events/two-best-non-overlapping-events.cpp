class Solution {
public:
    int n;
    int dp[2][100000];
    vector<int> next;
    int f(int i, int j, vector<vector<int>>& events){
        if(i >= 2 || j >= n) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int take = events[j][2] + f(i + 1, next[j], events);
        int skip = f(i, j + 1, events);
        return dp[i][j] = max(take, skip);
    }
    int maxTwoEvents(vector<vector<int>>& events) {
        n = events.size();
        sort(events.begin(),events.end());
        next.resize(n);
        memset(dp, -1, sizeof(dp));
        for(int i = 0; i < n; i++){
            next[i] = upper_bound(events.begin() + i, events.end(), vector<int> {events[i][1], INT_MAX, INT_MAX}) - events.begin();
        }
        return f(0,0,events);
    }
};