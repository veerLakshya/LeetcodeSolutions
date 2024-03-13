class Solution {
public:
    int pivotInteger(int n) {
        int sum=0;
        for(int i=n;i>0;i--)
        {
            sum+=i;
            if(sum==(i)*(i+1)/2)return i;
        }
        return -1;
    }
};