class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int n = differences.size() + 1;
        vector<long long> a(n, lower);
        for(long long i = 1; i < n; i++){
            a[i] = a[i-1] + differences[i-1];
        }
        long long add = 0, sub = 0;
        for(auto i: a){
            if(i < lower) add = max(add, lower - i);
        }
        for(auto &i: a) i += add;
        for(auto &i: a) cout << i << " ";
        long long m = INT_MIN;
        for(auto i: a){
            if(i <= upper) m = max(m, i);
            else return 0;
        }
        // cout<< m;
        return upper - m + 1;
    }
};