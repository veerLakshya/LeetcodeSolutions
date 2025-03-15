class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int ans = *max_element(nums.begin(),nums.end());
        int l = *min_element(nums.begin(),nums.end());
        int r = *max_element(nums.begin(),nums.end());
        while(l <= r){
            int mid = (l+r)/2;
            int cnt = nums[0] <= mid ? 1 : 0;
            bool f = (nums[0] <= mid);
            for(int i = 1; i < nums.size(); i++){
                if(nums[i] <= mid && !f){
                    cnt++;
                    f = 1;
                }
                else f = 0;
            }
            if(cnt >= k){
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
            // cout << mid << " " << cnt << endl;
        }
        return ans;
    }
};