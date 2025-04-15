class Solution {
public:
    // bool cmp(vector<int>& a, vector<int>& b){
    //     if(a.back() == b.back()) return a.front() < b.front();
    //     return a.back() < b.back();
    //     return false;
    // }
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // sort(trips.begin(), trips.end(), cmp());
        // for(auto i: trips) cout << i[2]<<endl;
        // return 0;
        int last = INT_MIN;
        for(auto i: trips){
            last = max(i[2], last);
        }
        vector<int> pas(last + 69, 0);
        for(auto i: trips){
            pas[i[2]] -= i[0];
            pas[i[1]] += i[0];
        }
        for(int i = 1; i <= last; i++) pas[i] += pas[i-1];
        for(int i = 0; i <= last; i++){
            if(pas[i] > capacity) return false;
        }
        return true;
    }
};