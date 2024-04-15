class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long low=0;
        long long high=1e14;
        long long ans=0;
        while(low<=high){
            long long mid=(low+high)/2;
            long long cnt=0;
            for(auto i:ranks){
                cnt+=sqrt(mid/i);
            }
            if(cnt>=cars){
                ans=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return ans;
        
    }
};