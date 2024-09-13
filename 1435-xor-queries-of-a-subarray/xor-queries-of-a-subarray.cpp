class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> ans(n), pre(arr.size());

        pre[0] = arr[0];
        for(int i = 1; i < arr.size(); i++){
            pre[i] = pre[i - 1] ^ arr[i];
        }

        for(int i = 0; i < n; i++){
            int left = queries[i][0];
            int right = queries[i][1];
            if(!left) ans[i] = pre[right];
            else ans[i] = pre[right] ^ pre[left - 1];
        }
        return ans; 
    }
};