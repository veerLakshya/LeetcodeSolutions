class Solution {
public:
    bool h(int num, int target){
        if(target < 0 || num < target) return false;
        if(num == target) return true;
        return h(num / 10, target - num % 10) || h(num/100 , target - num % 100) || h(num/1000, target - num% 1000);
    }
    int punishmentNumber(int n) {
        long long ans = 0;
        for(long long i = 1; i <= n; i++){
            if(h(i*i, i)) ans += i*i;
        }
        return ans;
    }
};