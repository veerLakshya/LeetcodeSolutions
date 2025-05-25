class Solution {
public:
    long long appealSum(string s) {
        long long ans = 0, n = s.size();
        set<char> st(s.begin(), s.end());
        for(auto i: st){
            long long cnt = 0, last = -1;
            for(int j = 0; j < n; j++){
                if(s[j] == i){
                    ans += (j + 1);
                    last = j;
                }
                else ans += (last + 1);
            }
            ans += cnt;
        }
        return ans;
    }
};