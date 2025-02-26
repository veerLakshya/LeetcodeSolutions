class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n+1);
        map<pair<int,int>, bool> connected;
        vector<int> degree(n+1, 0);
        for(auto i: edges){
            int x = i[0], y = i[1];
            degree[x]++,degree[y]++;
            connected[{x,y}] = 1;
            connected[{y,x}] = 1;
            adj[x].push_back(y);
            // adj[y].push_back(x);
        }
        int ans = INT_MAX;
        for(int i = 1; i <= n; i++){
            if(degree[i] >= 2){
                for(auto nbr: adj[i]){
                    if(degree[nbr] >= 2){
                        for(auto c: adj[nbr]){
                            if(degree[c] < 2) continue;
                            if(connected.count({i,c})){
                                ans = min(ans, degree[i]+degree[nbr]+degree[c] - 6);
                            }
                        }
                    }
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};