class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(n+3, 0);
        for(auto i: nums) if(i > 0 && i <= n) freq[i]++;
        for(int i = 1; i <= n + 1; i++) if(!freq[i]) return i;
        return 0;
    }
};