class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num==1)return 1;
        long long low=1;
        long long high=num/2;
        long long ans=0;
        while(low<=high){
            long long mid = low +(high-low)/2;
            if(mid*mid<=num){
                ans=mid;
                low=mid+1;
            }
            else
            high=mid-1;
        }
        return ans*ans==num?1:0;
        
    }
};