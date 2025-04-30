#include <cmath>
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for(auto i: nums) if(int(log10(i)+1)%2 == 0) ans++;
        return ans;
    }
};