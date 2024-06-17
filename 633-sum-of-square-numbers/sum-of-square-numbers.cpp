class Solution {
public:
    bool judgeSquareSum(int c) {
        long long l = 0, r = sqrt(c);
        while(l<=r){
            long long val = l*l + r*r; 
            if(val==c){
                cout<<l<<" "<<r;
                return true;
            }
            else if(val < c) l++;
            else r--;
        }
        return false;
    }
};