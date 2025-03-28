class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        vector<int> dx = {0,0,1,-1}, dy = {-1,1,0,0};
        int n = grid.size(), m = grid[0].size();

        vector<pair<int,int>> sortedqueries;
        for(int i = 0; i < queries.size(); i++) sortedqueries.push_back({queries[i], i});
        sort(sortedqueries.begin(),sortedqueries.end());

        vector<int> ans(queries.size(), 0);
        vector<vector<int>> visited(n , vector<int> (m, 0));

        priority_queue< array<int,3>, vector<array<int,3>>, greater<>> pq;
        pq.push({grid[0][0],0,0});
        visited[0][0] = 1;

        int total = 0;
        for(auto query: sortedqueries){
            while(pq.size() && pq.top()[0] < query.first){
                total++;
                array<int,3> cur = pq.top();
                pq.pop();
                for(int k = 0; k < 4; k++){
                    int x = cur[1] + dx[k];
                    int y = cur[2] + dy[k];
                    if(x >= 0 && y >= 0 && x < n && y < m && !visited[x][y]){
                        pq.push({grid[x][y], x, y});
                        visited[x][y] = 1;
                    }
                }
            }
            ans[query.second] = total;
        }
        return ans;
    }
};