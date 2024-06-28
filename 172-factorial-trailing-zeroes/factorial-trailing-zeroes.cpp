class Solution {
public:
    int trailingZeroes(int n) {
        int ans=0;
        while(n>4){
            ans+= n/5;
            n=n/5;
        }
        return ans;
    }
};