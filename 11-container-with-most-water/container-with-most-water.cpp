class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0, l = 0, r = height.size() - 1;
        while(l < r){
            ans = max(ans, abs(l-r)*min(height[l],height[r]));
            if(height[l] < height[r])l++;
            else r--;
        }
        return ans;
    }
};