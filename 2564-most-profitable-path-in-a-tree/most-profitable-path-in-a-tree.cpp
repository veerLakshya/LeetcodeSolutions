class Solution {
public:
    vector<int> vis;
    vector<vector<int>> adj;
    unordered_map<int,int> bobpath;

    bool findbobpath(int cur, int time){
        bobpath[cur] = time;
        vis[cur] = 1;
        if(cur == 0) return true;
        for(auto nbr: adj[cur]){
            if(vis[nbr]) continue;
            if(findbobpath(nbr, time + 1))return true;
        }
        bobpath.erase(cur);
        return false;
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size(), ans = INT_MIN;
        adj.resize(n);
        vis.assign(n, 0);

        for(auto i: edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        findbobpath(bob, 0);
        vis.assign(n,0);

        queue<array<int,3>> q; // node, time, income
        q.push({0,0,0});

        while(q.size()){
            int cur = q.front()[0];
            int time = q.front()[1];
            int income = q.front()[2];
            q.pop();
            vis[cur] = 1;
            if(bobpath.find(cur) == bobpath.end() || time < bobpath[cur]) income += amount[cur];
            else if(time == bobpath[cur]) income += amount[cur]/2;

            if(adj[cur].size() == 1 && cur != 0) ans = max(ans, income);

            for(auto nbr: adj[cur]){
                if(vis[nbr]) continue;
                q.push({nbr, time + 1, income});
            }
        }
        return ans;
    }
};