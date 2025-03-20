class UnionFind {
private:
    int n;
    vector<int> par, rank;
public:
    UnionFind(int x) {
        n = x;
        par.resize(n, 0);
        rank.resize(n, 0);
        iota(par.begin(), par.end(), 0);
    }
    int findPar(int i) {
        if (par[i] == i)
            return i;
        return par[i] = findPar(par[i]);
    }
    bool isSame(int i, int j) { return findPar(i) == findPar(j); }
    void merge(int i, int j) {
        i = findPar(i), j = findPar(j);
        if (i == j) return;
        if (rank[i] > rank[j])
            swap(i, j);
        par[i] = j;
        if (rank[j] == rank[i])
            rank[j]++;
    }
};
class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges,
                            vector<vector<int>>& query) {
        UnionFind dsu(n);
        vector<int> cost(n,-1); // as binary of -1 is all 1s
        for(auto i: edges){
            dsu.merge(i[0],i[1]);
        }
        for(auto i: edges){
            cost[dsu.findPar(i[0])] &= i[2];
        }
        vector<int> ans;
        for(auto i: query){
            if(dsu.isSame(i[0],i[1])){
                ans.push_back(cost[dsu.findPar(i[0])]);
            }
            else ans.push_back(-1);
        }
        return ans;
    }
};