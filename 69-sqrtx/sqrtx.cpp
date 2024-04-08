class Solution {
public:
    bool check(long long i, long long x){
        return i*i <= x;
    }
    int mySqrt(int x) {
        if(x==0)return 0;
        long long low = 1;
        long long high = x;
        long long ans = 0;
        while(low<=high){
            long long mid = (low+high)/2;
            if(check(mid,x)){
                ans=mid;
                low=mid+1;
            }
            else
            high = mid -1;
        }
        return ans;
        
    }
};