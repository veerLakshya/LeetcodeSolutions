class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int ans = 1, n = nums.size(), l = 0, r = n;
        while(l <= r){
            int mid = (l+r)/2;
            bool possible = false;
            for(int i = 0; i <= n - mid; i++){
                int mask = 0;
                bool f = true;
                for(int j = i; j < i + mid; j++){
                    if((mask & nums[j]) != 0){
                        f = false;
                        break;
                    }
                    mask |= nums[j];
                }
                if(f){
                    possible = 1;
                    break;
                }
            }
            if(possible){
                ans = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        return ans;
    }
};