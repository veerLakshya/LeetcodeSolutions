class Solution {
public:
    void dbg(vector<int> a){
        for(auto i: a) cout << i <<" ";
        cout << endl;
    }
    // int dfs1(int node, int par, int d, int o, vector<int>& even, vector<int>& odd, auto& adj){
    //     for(auto nbr: adj[node]){
    //         if(nbr == par) continue;
    //         cnt += dfs1(nbr, node, d + 1, o, a, adj);
    //         even[node] += cnt;
    //     }
    //     return cnt;
    // }
    void h(int node, int par, int col, auto& color, auto& adj){
        color[node] = col;
        for(auto nbr: adj[node]){
            if(nbr == par) continue;
            h(nbr, node, !col, color, adj);
        }
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size(), m = edges2.size();
        n++,m++;
        vector<vector<int>> adj1(n), adj2(m);
        vector<int> color1(n, -1), color2(m,-1), ans(n, 1);
        for(auto i: edges1){
            adj1[i[0]].push_back(i[1]);
            adj1[i[1]].push_back(i[0]);
        }
        for(auto i: edges2){
            adj2[i[0]].push_back(i[1]);
            adj2[i[1]].push_back(i[0]);
        }
        // vector<int> odd1(n, 0), even1(n, 1);
        // vector<int> odd2(n, 0), even2(n, 0);

        // dfs1(0, -1, 0, 0, even1, odd1, adj1);

        // cout << "even1 : "; dbg(even1);
        // cout << "odd1 : "; dbg(odd1);
        h(0,-1, 0, color1, adj1);
        int max0 = count(color1.begin(), color1.end(), 0);
        int max1 = n-max0;
        h(0, -1, 0, color2, adj2);
        int odd = count(color2.begin(), color2.end(), 0);
        int even = m - odd;
        for(int i = 0; i < n; i++) ans[i] = (color1[i] == 1 ? max1: max0) + max(even, odd);
        return ans;
    }
};