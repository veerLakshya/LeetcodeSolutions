class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> adj(n);
        for(auto i: edges){
            adj[i[0]].push_back(i[1]);
        }
        
        vector<int> state(n, 0);
        vector<vector<int>> freq(n, vector<int> (26, 0));
        
        int ans = 0;
        bool cycle = false;
        
        function<void(int)> dfs = [&](int cur){
            state[cur] = 1;
            for(auto nbr: adj[cur]){
                if(state[nbr] == 1) {
                    cycle = 1;
                    return;
                }
                else if(!state[nbr] || state[nbr] == 2){
                    if(!state[nbr]) dfs(nbr);
                    for(int c = 0; c < 26; c++){
                        freq[cur][c] = max(freq[cur][c], freq[nbr][c]);
                        ans = max(ans, freq[cur][c]);
                    }
                }
            }
            freq[cur][colors[cur] - 'a']++;
            ans = max(ans, freq[cur][colors[cur]-'a']);
            state[cur] = 2;
        };
        for(int i = 0; i < n; i++){
            if(!state[i]){
                dfs(i);
                if(cycle) return -1;
            }
        }
        return ans;
    }
};