class Solution {
public:
    int ans = INT_MAX;
    void helper(vector<int>& a, vector<int>& child, int ind, int k){
        if(ind == a.size()){
            ans = min(ans, *max_element(child.begin(), child.end()));
            return;
        }
        for(int i = 0; i < k; i++){
            child[i] += a[ind];
            helper(a, child, ind + 1, k);
            child[i] -= a[ind];
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> temp(k, 0);
        helper(cookies, temp, 0, k);
        return ans;
    }
};