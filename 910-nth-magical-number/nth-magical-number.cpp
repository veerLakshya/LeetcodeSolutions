class Solution {
public:
    bool check(long long x,int n,int a, int b){
        long long t = x/a;
        t += x/b;
        t -= x/(a*b/gcd(a,b));
        cout<<x<<" "<<t<<"*";
        return t>=n;
    }
    int nthMagicalNumber(int n, int a, int b) {
        long long low=1;
        
        unsigned long long  high=LONG_LONG_MAX;
        long long ans=-1;
        const unsigned int M = 1000000007;
        while(low<=high){
            long long mid = (low+high)/2;
            cout<<low<<" "<<high<<"|";
            if(check(mid,n,a,b)){
                ans = mid;
                high = mid-1;
            }
            else
            low = mid+1;
            cout<<low<<" "<<high<<"|"<<endl;
        }
        return ans%(M);
    }
};