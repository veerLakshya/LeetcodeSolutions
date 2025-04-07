typedef long long ll;
class Solution {
public:
    ll n, K, prenums[1001]{0}, precost[1001]{0}, dp[1001];
    ll helper(ll ind, auto& nums){
        if(ind >= n) return 0;
        if(dp[ind]!= -1) return dp[ind];
        ll cost = 1e18;
        for(ll i = ind; i < n; i++){
            ll opt = (prenums[i+1]) * (precost[i+1] - precost[ind]);
            opt += K * (precost[n] - precost[ind]);
            opt += helper(i + 1, nums);
            cost = min(cost, opt);
        }
        return dp[ind] = cost;
    }
    long long minimumCost(vector<int>& nums, vector<int>& cost, int k) {
        memset(dp, -1, sizeof dp);
        n = nums.size();
        K = k;
        for(ll i = 1; i <= n; i++){
            prenums[i] = prenums[i-1] + nums[i-1];
            precost[i] = precost[i-1] + cost[i-1];
        } 
        return helper(0, nums);
    }
};