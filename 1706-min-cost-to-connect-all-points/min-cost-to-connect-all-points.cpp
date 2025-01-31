
class UnionFind {
private:
    vector<int> p, rank;
public:
    UnionFind(int n) {
        rank.assign(n, 0);
        p.assign(n, 0);
        iota(p.begin(), p.end(), 0);
    }

    int findSet(int i) {
        return (p[i] == i) ? i : (p[i] = findSet(p[i]));
    }

    bool isSameSet(int i, int j) {
        return findSet(i) == findSet(j);
    }

    void unionSet(int i, int j) {
        if (!isSameSet(i, j)) {
            int x = findSet(i), y = findSet(j);
            if (rank[x] > rank[y]) p[y] = x;
            else {
                p[x] = y;
                if (rank[x] == rank[y]) rank[y]++;
            }
        }
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        // unordered_map<pair<int,int>,int>> id;
        int n = points.size();
        vector<vector<int>> edj;
        for(int i = 0; i < n; i++){
            int x1 = points[i][0];
            int y1 = points[i][1];
            for(int j = i+1; j < n; j++){
                int x2 = points[j][0];
                int y2 = points[j][1];
                int wt = abs(x1-x2) + abs(y1-y2);
                edj.push_back({wt,i,j});
            }
        }
        sort(edj.begin(),edj.end());
        UnionFind dsu(n+1);
        int ans = 0;
        for(auto i: edj){
            if(!dsu.isSameSet(i[1],i[2])){
                ans += i[0];
                dsu.unionSet(i[1],i[2]);
            }
        }
        return ans;
    }
};