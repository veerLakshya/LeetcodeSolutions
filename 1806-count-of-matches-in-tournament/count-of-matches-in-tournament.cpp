class Solution {
public:
    int numberOfMatches(int n) {
        if(n==1||n==0)return 0;
        if(n==2)return 1;
        int cnt=0;
        while(n>2){
            cnt+=(n/2);
            if(n%2!=0){
                n=n/2;
                n++;
            }
            else
            n=n/2;
        }
        return cnt+1;
    }
};