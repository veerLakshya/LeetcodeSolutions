class Solution {
public:
    int countDigits(int num) {
        int x=num;
        int ans=0;
        while(x>0){
            int dig=x%10;
            if(num%dig==0)ans++;
            x/=10;
        }
        return ans;
    }
};