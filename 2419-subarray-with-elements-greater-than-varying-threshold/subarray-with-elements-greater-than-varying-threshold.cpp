struct DSU{
    int mx = 1;
    vector<int> par, size;
    DSU(int n){
        par.resize(n+1);
        size.resize(n+1, 1);
        iota(par.begin(),par.end(), 0);
    }
    int findPar(int x){
        if(par[x] == x) return x;
        return par[x] = findPar(par[x]);
    }
    void merge(int x, int y){
        x = findPar(x);
        y = findPar(y);

        if(x == y) return;
        if(size[x] > size[y]) swap(x, y);

        size[y] += size[x];
        par[x] = y;

        mx = max (mx, size[y]);
    }
};
class Solution {
public:
    int validSubarraySize(vector<int>& nums, int threshold) {
        int n = nums.size(), k = 1;

        vector<pair<double,int>> p; // val, ind
        for(int i = 0; i < n; i++){
            p.push_back({nums[i], i + 1});
        }

        sort(p.rbegin(), p.rend());

        vector<bool> active(n+1, 0);
        DSU dsu(n);

        for(int i = 0; i < n && k <= n;){
            double newt = (double)(threshold/k);
            while(i < n && p[i].first > newt){
                int ind = p[i].second;
                active[ind] = 1;
                if(active[ind-1]) dsu.merge(ind, ind-1);
                if(active[ind+1]) dsu.merge(ind, ind+1);
                i++;
            }
            if(i > 0 && dsu.mx >= k) return k;
            k++;
        }
        return -1;
    }
};