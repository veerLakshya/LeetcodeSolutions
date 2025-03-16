class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long  n = ranks.size(), l = 0, r = 1e16, ans = 1e16;

        while(l <= r){
            long long  mid = (l+r)/2;
            long long  cnt = 0;
            for(long long  i = 0; i < n; i++){
                cnt += sqrt(mid / ranks[i]);
            }
            if(cnt >= cars){
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        } 
        return ans;
    }
};