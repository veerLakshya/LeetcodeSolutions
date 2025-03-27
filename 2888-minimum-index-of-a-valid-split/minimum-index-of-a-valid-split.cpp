class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int cnt = 0, n = nums.size();
        map<int,int> freq;
        for(auto i: nums) freq[i]++;
        int occ = -1, ele = -1;
        for(auto i: freq) if(i.second > occ) ele = i.first, occ = i.second;
        cnt = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == ele) cnt++;
            int rem = occ - cnt;
            if(cnt*2 > i + 1 && rem*2 > n - i - 1) return i;
            // cout << cnt << " "; 
        }
        return -1;
    }
};