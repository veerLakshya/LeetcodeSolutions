class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<int> dx = {0, 0, 1, -1}, dy = {1, -1, 0, 0};
        vector<vector<int>> vis(n, vector<int>(m, 0));
        set<pair<int, int>> sta, stb;
        queue<pair<int, int>> q;
        for(int i = 0; i < m; i++){
            q.push({0, i});
            vis[0][i] = 1;
        }
        for(int j = 0; j < n; j++){
            q.push({j, 0});
            vis[j][0] = 1;
        }
        while (q.size()) {
            pair<int, int> cur = q.front();
            q.pop();
            sta.insert(cur);
            for (int i = 0; i < 4; i++) {
                int x = cur.first + dx[i];
                int y = cur.second + dy[i];
                if (x >= 0 && y >= 0 && x < n && y < m && !vis[x][y] &&
                    heights[x][y] >= heights[cur.first][cur.second]) {
                    vis[x][y] = 1;
                    q.push({x, y});
                }
            }
        }
        vis.assign(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++){
            q.push({i, m-1});
            vis[i][m-1] = 1;
        }
        for(int i = 0; i < m; i++){
            q.push({n-1, i});
            vis[n-1][i] = 1;
        }
        while (q.size()) {
            pair<int, int> cur = q.front();
            q.pop();
            stb.insert(cur);
            for (int i = 0; i < 4; i++) {
                int x = cur.first + dx[i];
                int y = cur.second + dy[i];
                if (x >= 0 && y >= 0 && x < n && y < m && !vis[x][y] &&
                    heights[x][y] >= heights[cur.first][cur.second]) {
                    vis[x][y] = 1;
                    q.push({x, y});
                }
            }
        }
        vector<vector<int>> ans;
        for(auto i: sta){
            if(stb.count(i)){
                ans.push_back({i.first,i.second});
            }
        }
        return ans;
    }
};