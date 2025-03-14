class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();
        long long l = 1, r = *max_element(candies.begin(),candies.end()), ans = 0;
        while(l <= r){
            long long mid = r - (r - l)/2;
            long long cur = 0;
            for(auto i: candies){
                cur += i/mid;
            }
            if(cur >= k){
                ans = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        return ans;
    }
};