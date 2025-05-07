class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        vector<int> dx = {0, 0, 1, -1}, dy = {1, -1, 0, 0};
        int n = moveTime.size(), m = moveTime[0].size();
        int ans = 1e9 + 5;
        vector<vector<int>> vis(n, vector<int>(m, -1));
        auto cmp = [](array<int,3> a, array<int,3> b){
            return a[2] > b[2];
        };
        priority_queue<array<int, 3>, vector<array<int,3>>, decltype(cmp)> q;
        q.push({0, 0, 0});
        vis[0][0] = 0;
        auto h = [&](int a, int b) -> bool {
            if (a >= n || b >= m)
                return 0;
            if (a < 0 || b < 0)
                return 0;
            return 1;
        };
        while (q.size()) {
            auto cur = q.top();
            q.pop();
            if (cur[2] > vis[cur[0]][cur[1]]) continue;
            for (int k = 0; k < 4; k++) {
                int x = cur[0] + dx[k];
                int y = cur[1] + dy[k];
                if (h(x, y) && vis[x][y] == -1) {
                    vis[x][y] = (cur[2] > moveTime[x][y] ? cur[2] : moveTime[x][y]) + 1;
                    q.push({x, y, vis[x][y]});
                }
            }
        }
        return vis[n - 1][m - 1];
    }
};