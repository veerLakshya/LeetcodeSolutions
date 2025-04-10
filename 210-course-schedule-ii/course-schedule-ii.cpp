class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> vis( n, 0), indegree(n, 0), ans;
        vector<vector<int>> adj(n);
        for(auto i: prerequisites){
            adj[i[0]].push_back(i[1]);
            indegree[i[1]]++;
        } 
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(!indegree[i]) q.push(i);
        }
        while(q.size()){
            int cur = q.front();
            q.pop();
            ans.push_back(cur);
            for(auto nbr: adj[cur]){
                indegree[nbr]--;
                if(indegree[nbr] == 0) q.push(nbr);
            }
        }
        reverse(ans.begin(), ans.end());
        if(ans.size() == n) return ans;
        return {};
    }
};