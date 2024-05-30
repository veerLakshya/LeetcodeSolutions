class Solution {
public:
    double power(double x, int n){
        if(n==1)return x;
        if(n==0)return(double )1;
        double temp=power(x,n/2);
        return temp*temp*(n%2==0 ? 1: x); 
    }
    double myPow(double x, int n) {
        if(n==0)return 1;
        else if(n<0)return 1/power(x,abs(n));
        else return power(x,n);
    }
};