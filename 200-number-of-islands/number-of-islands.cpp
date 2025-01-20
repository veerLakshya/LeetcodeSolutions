class Solution {
public:
    vector<int> dx = {1, -1, 0, 0}, dy = {0, 0, 1, -1};

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        map< pair<int,int>, vector<pair<int,int>> > edges;
        set<pair<int,int>> validNodes;
        map<pair<int,int>, bool> vis;
        for(int i = 0; i < m ; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '0') continue;
                validNodes.insert({i,j});
                vis[{i,j}] = 0;
                for(int k = 0; k < 4; k++){
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if(x >= 0 && x < m  && y >= 0 && y < n){
                        if(grid[x][y] == '1') edges[{i,j}].push_back({x,y});
                    }
                }
            }
        }
        auto dfs = [&](pair<int,int> curNode, auto self)-> void{
            vis[curNode] = 1;
            for(auto nbr: edges[curNode]){
                if(!vis[nbr]) self(nbr, self);
            }
        };
        int ans = 0;
        for(auto i: validNodes){
            if(!vis[i]){
                ans++;
                dfs(i, dfs);
            }
        }
        return ans;
    }
};