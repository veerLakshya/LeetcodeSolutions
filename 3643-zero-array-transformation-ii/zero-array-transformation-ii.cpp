class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), m = queries.size(), ans = -1;
        int l = 0, r = m;

        auto possible = [&](int mid)->bool{
            vector<int> pre(n + 1, 0);
            for(int i = 0; i < mid; i++){
                int lind = queries[i][0];
                int rind = queries[i][1];
                int val = queries[i][2];
                pre[lind] -= val;
                pre[rind+1] += val;
            }
            for(int i = 1; i <= n; i++) pre[i] += pre[i-1];
            for(int i = 0; i < n; i++){
                if(nums[i] + pre[i] > 0)return false;
            }
            return true;
        };

        while(l <= r){
            int mid = (l+r)/2;
            if(possible(mid)){
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return ans;
    }
};