class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long n = grid.size(), m = grid[0].size();
        unordered_multiset<long long> st1,st2;
        long long total = 0;
        for(auto i: grid){
            total += accumulate(i.begin(), i.end(), 0ll);
            st1.insert(i.begin(), i.end());
        }
        if(n == 1){
            long long temp = 0;
            for(long long j = 0; j < m; j++){
                temp += grid[0][j];
                if(2*temp == total) return true;
                if(2*temp > total && j > 0){
                    long long l = grid[0][0];
                    long long r = grid[0][j];
                    if(2*(temp-l) == total - l) return true;
                    if(2*(temp - r) == total - r) return true;
                }
                else{
                    long long l = (j+1 < m ? grid[0][j+1] : 0);
                    long long r = (j != m - 1 ? grid[0][m-1] : 0);
                    if(2*temp == total - l) return true;
                    if(2*temp == total - r) return true;
                }
            }
            return false;
        }
        if(m == 1){
            long long temp = 0;
            for(long long i = 0; i < n; i++){
                temp += grid[i][0];
                if(2*temp == total) return true;
                if(2*temp > total && i > 0){
                    long long l = grid[0][0];
                    long long r = grid[i][0];
                    if(2*(temp - l) == total - l) return true;
                    if(2*(temp - r) == total - r) return true;
                }
                else{
                    long long l = (i+1 < n ? grid[i + 1][0] : 0);
                    long long r = (i != n - 1 ? grid[n - 1][0] : 0);
                    if(2*temp == total - l) return true;
                    if(2*temp == total - r) return true;
                }
            }
            return false;
        }
        // cout << total << endl;
        long long cur = 0;
        for(long long i = 0; i < n; i++){
            for(long long j = 0; j < m; j++){
                cur += grid[i][j];
                st2.insert(grid[i][j]);
                st1.erase(st1.find(grid[i][j]));
            }
            cout << cur << endl;
            if(cur*2 == total) return true;
            if(i == 0){
                long long f = grid[i][0];
                long long l = grid[i][m-1];
                if(2*(cur-f) == total - f) return true;
                if(2*(cur-l) == total - l) return true;
            }
            if(i == n - 2){
                long long f = grid[n-1][0];
                long long l = grid[n-1][m-1];
                if(2*cur == total - f) return true;
                if(2*cur == total - l) return true;
            }
            else{
                long long req = -1;
                if(cur*2 > total){
                    req = 2 * cur - total;
                    if(st2.find(req) != st2.end()) return true;
                }
                else {
                    req = total - 2 * cur;
                    if(st1.find(req) != st1.end()) return true;
                }
            }
        }
        st1.clear();
        st2.clear();
        cur = 0;
        for(auto i: grid){
            st1.insert(i.begin(), i.end());
        }
        for(long long j = 0; j < m; j++){
            for(long long i = 0; i < n; i++){
                cur += grid[i][j];
                st2.insert(grid[i][j]);
                st1.erase(st1.find(grid[i][j]));
            }
            if(cur*2 == total) return true;
            if(j == 0){
                long long f = grid[0][0];
                long long l = grid[n-1][0];
                if(2*(cur-f) == total - f) return true;
                if(2*(cur-l) == total - l) return true;
            }
            if(j == m - 2){
                long long f = grid[0][m-1];
                long long l = grid[n-1][m-1];
                if(2*cur == total - f) return true;
                if(2*cur == total - l) return true;
            }
            else{
                long long req = -1;
                if(cur*2 > total){
                    req = 2 * cur - total;
                    if(st2.find(req) != st2.end()) return true;
                }
                else {
                    req = total - 2 * cur;
                    if(st1.find(req) != st1.end()) return true;
                }
            }
        }
        return false;
    }
};