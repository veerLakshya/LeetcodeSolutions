class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for(int i = low; i <= min(high, 100); i++){
            if(i < 100 && i % 11 == 0) ans++;
        }
        for(int i = max(low,1001); i <= min(10000, high); i++){
            int left = (i/1000 + (i%1000)/100);
            int right = i%10 + (i/10 % 10);
            if(left == right) ans++;
        }
        return ans;
    }
};