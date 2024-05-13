class Solution {
public:
    int minOperations(int n) {
        int ans=0;
        int i=1,j=2*(n-1)+1;
        while(i<j){
            ans+= (j-i)/2;
            i+=2;
            j-=2;
        }
        return ans;
    }
};
// 1 3 5 7 9