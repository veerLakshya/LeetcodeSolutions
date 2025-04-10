class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adj(n);
        for(auto i: prerequisites){
            adj[i[0]].push_back(i[1]);
        } 
        vector<int> vis( n, 0), instack(n, 0);
        int cycle = 0;
        function<void(int)> dfs = [&](int cur)-> void{
            vis[cur] = instack[cur] = 1;
            for(auto nbr: adj[cur]){
                if(!vis[nbr]) dfs(nbr);
                else if(instack[nbr]) cycle = 1;
            }
            instack[cur] = 0;
        };
        for(int i = 0; i < n; i++){
            if(!vis[i]) dfs(i);
            if(cycle) return 0;
        }
        return !cycle;
    }
};