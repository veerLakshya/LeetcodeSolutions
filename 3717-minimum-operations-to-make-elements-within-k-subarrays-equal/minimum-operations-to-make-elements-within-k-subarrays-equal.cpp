typedef long long ll;

class Solution {
public:
    vector<ll> medians;
    vector<vector<ll>> dp;
    ll h(int ind, int req, int x){
        if(req == 0) return 0;
        if(ind - x + 1 < 0) return 1e18;
        if(dp[ind][req] != -1) return dp[ind][req];
        ll op1 = medians[ind - x + 1] + h(ind-x, req -1, x);
        ll op2 = h(ind - 1, req, x);
        return dp[ind][req] = min(op1, op2);
    }
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        ll lowsum = 0, highsum = 0;

        multiset<ll> low, high;
        for(int i = 0; i < x; i++){
            low.insert(nums[i]);
            lowsum += nums[i];
        }
        while(low.size() > (x+1)/2){
            ll temp = *prev(low.end());
            low.erase(prev(low.end()));
            high.insert(temp);
            highsum += temp;
            lowsum -= temp;
        }
        ll rightval = highsum - high.size()*(*prev(low.end()));
        ll leftval = (low.size()*(*prev(low.end())) - lowsum);
        if(leftval < 0) leftval *= -1;
        if(rightval < 0) rightval *= -1;
        medians.push_back(rightval + leftval);

        for(int i = x; i < n; i++){
            if(low.count(nums[i-x])){
                lowsum -= nums[i-x];
                low.erase(low.find(nums[i-x]));
            }
            else{
                highsum -= nums[i-x];
                high.erase(high.find(nums[i-x]));
            }

            if (!low.empty() && nums[i] > *prev(low.end())) {
                high.insert(nums[i]);
                highsum += nums[i];
            } else {
                low.insert(nums[i]);
                lowsum += nums[i];
            }

            while(!high.empty() && low.size() < (x+1)/2){
                ll temp = *high.begin();
                highsum -= temp;
                lowsum += temp;
                low.insert(temp);
                high.erase(high.find(temp));
            }
            while(low.size() > (x+1)/2){
                ll temp = *prev(low.end());
                highsum += temp;
                lowsum -= temp;
                low.erase(low.find(temp));
                high.insert(temp);
            }
            leftval = ((*low.rbegin())*low.size() - lowsum);
            rightval = (highsum - high.size() * (*low.rbegin()));
            if(leftval < 0) leftval *= -1;
            if(rightval < 0) rightval *= -1;
            medians.push_back(leftval+rightval);
        }
        dp.assign(n, vector<ll> (k+1, -1));
        // for(auto i: medians) cout << i << " ";
        // cout << n<< " " << medians.size() <<" "<< n - x;
        return h(n-1, k, x);
        return 0;
    }
};
