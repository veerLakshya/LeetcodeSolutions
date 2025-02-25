class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int cur = 0, o = 0, e = 1, ans = 0, mod = 1e9+7;
        for(auto i: arr){
            cur += i;
            if(cur%2) o++;
            else e++;
            if(cur % 2 == 0) ans += o;
            else ans += e;
            ans %= mod;
        }
        return ans;
    }
};