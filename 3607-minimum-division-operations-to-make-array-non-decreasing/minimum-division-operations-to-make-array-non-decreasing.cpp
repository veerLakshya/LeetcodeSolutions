class Solution {
public:
    int getFactors(int n) {
        for (int i = 2; i <= n/2; ++i) {
            if (n % i == 0) return n / i;
        }
        return -1;
    }
    bool isPrime(int n) {
        if (n <= 1) return false; 
        if (n <= 3) return true;
        if (n % 2 == 0 || n % 3 == 0) return false; 
        for (int i = 5; i * i <= n; i += 6) { 
            if (n % i == 0 || n % (i + 2) == 0) return false;
        }
        return true; 
    }
    int minOperations(vector<int>& nums) {
        int ans = 0, n = nums.size();
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] > nums[i + 1]) {
                if (isPrime(nums[i]))
                    return -1;
                else{
                    int fact = getFactors(nums[i]);   
                    nums[i] = nums[i]/fact;
                    if(nums[i] > nums[i+1]) return -1;
                    ans++;
                }
            }
        }
        return ans;
    }
};