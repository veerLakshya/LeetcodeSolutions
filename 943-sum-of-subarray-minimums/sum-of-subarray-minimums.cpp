class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        long long n = arr.size();
        long long ans = 0, mod = 1e9 + 7;
        vector<long long> l(n),r(n);
        stack<pair<long long,long long>> pre, post;
        for(long long i = 0; i < n; i++){
            while(pre.size() && pre.top().first >= arr[i]) pre.pop();
            l[i] = (pre.size() ? pre.top().second : -1);
            pre.push({arr[i], i});
        }
        for(long long i = n - 1; i >= 0; i--){
            while(post.size() && post.top().first > arr[i]) post.pop();
            r[i] = (post.size() ? post.top().second : n);
            post.push({arr[i], i});
        }

        for(long long i = 0 ; i < n; i++){
            long long  leftsize = i - l[i];
            long long rightsize = r[i] - i;
            ans += (long long)leftsize%mod*rightsize%mod*(long long)arr[i]%mod;
            ans %= mod;
            // cout << ans << " ";
        }

        return ans;
    }
};