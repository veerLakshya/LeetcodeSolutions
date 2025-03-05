class Solution {
public:
    long long coloredCells(int n) {
        long long ans = 1, i = 1;
        while(i <= n){
            ans += 4*(i-1);
            i++;
        }
        return ans;
    }
};