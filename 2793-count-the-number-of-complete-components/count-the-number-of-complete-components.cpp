class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int ans = 0;
        vector<int> par(n, 0), rank(n, 0), nbrs(n, 0);
        iota(par.begin(), par.end(), 0);
        function<int(int)> findPar = [&](int i)->int{
            if(par[i] == i) return i;
            return par[i] = findPar(par[i]);
        };
        auto merge = [&](int i, int j)->void{
            i = findPar(i), j = findPar(j);
            if(i == j) return;
            if(rank[i] > rank[j]) swap(i, j);
            par[i] = j;
            if(rank[i] == rank[j]) rank[j]++;
        };
        for(auto i: edges){
            merge(i[0], i[1]);
            nbrs[i[0]]++;
            nbrs[i[1]]++;
        }
        map<int, vector<int>> components;
        for(int i = 0; i < n; i++){
            components[par[i]].push_back(i);
        }
        for(auto i: components){
            int x = i.second.size();
            // cout << i.first<<endl;
            int f = 1;
            // for(auto j: i.second) cout << j << " ";
            // cout << endl;
            for(int j = 0; j < x; j++){
                if((nbrs[i.second[j]] != x - 1)){
                    f = 0;
                    break;
                }
            }
            if(f) ans++;
        }
        return ans;
    }
};