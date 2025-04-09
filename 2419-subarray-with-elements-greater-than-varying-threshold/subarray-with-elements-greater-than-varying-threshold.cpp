struct DSU {
    int mx;
    vector<int> par, size;
    
    DSU (int n) {
        mx = 1;
        par.resize(n+1);
        size.resize(n+1, 1);
        
        for (int j = 1; j <= n; j ++) par[j] = j;
    }
    
    int Leader (int x) {
        if (par[x] == x) return x;
        return (par[x] = Leader (par[x]));
    }
    
    void merge (int x, int y) {
        x = Leader(x);
        y = Leader(y);
        
        if (x == y) return;
        if (size[x] > size[y]) swap (x, y);
        
        size[y] += size[x];
        par[x] = y;
        
        mx = max (mx, size[y]);
    }
};

class Solution {
public:
    int validSubarraySize(vector<int>& nums, int threshold) {
        int n = nums.size();
        
        vector<pair<double, int>> val_and_ind;
        for (int j = 0; j < n; j ++) {
            val_and_ind.push_back({nums[j], j+1});           
        }
        
        sort (val_and_ind.begin(), val_and_ind.end());
        
        vector<bool> active (n+1, false);
        int k = 1;
        DSU dsu(n);
        
        for (int j = n-1; j >= 0 && k <= n;) {
            double k_threshold = (double)threshold/k;
            
            while (j >= 0 && val_and_ind[j].first > k_threshold) {
                int ind = val_and_ind[j].second;
                active[ind] = true;
                
                if (active[ind-1]) dsu.merge (ind, ind-1);
                if (active[ind+1]) dsu.merge (ind, ind+1);
                
                j --;
            }
                        
            if (j < n-1 && dsu.mx >= k) return k;
            k ++;
        }
        
        return -1;
    }
};