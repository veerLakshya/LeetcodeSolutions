class node{
    public:
    int x,y,t,f;
    node(int _x, int _y, int _t, int _f){
        x = _x;
        y = _y;
        t = _t;
        f = _f;
    }
};
class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        vector<int> dx = {0,0,-1,1}, dy = {1,-1,0,0};
        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<int>> vis(n, vector<int> (m, -1));
        auto cmp=[](node a, node b){
            return a.t > b.t;
        };
        priority_queue<node, vector<node>, decltype(cmp)> q; 
        q.push(node(0,0,0,2));
        vis[0][0] = 0;
        while(q.size()){
            node cur = q.top();
            q.pop();
            if(cur.x == n-1 && cur.y == m - 1) return cur.t;
            // if(vis[cur.x][cur.y] != -1) continue;
            for(int k = 0; k < 4; k++){
                int x = cur.x + dx[k];
                int y = cur.y + dy[k];
                if(x >= 0 && x < n && y >= 0 && y < m && vis[x][y] == -1){
                    vis[x][y] = max(moveTime[x][y], cur.t) + (cur.f == 1 ? 2 : 1);
                    q.push(node{x, y, vis[x][y], (cur.f == 1 ? 2 : 1)});
                }
            }
        }
        return vis[n-1][m-1];
    }
};