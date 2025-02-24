class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans = 0, sum = 0, n = arr.size();
        for(int i = 0; i < n; i++){
            sum += arr[i];
            if(sum == (i+1)*(i)/2) ans++;
        }
        return ans;
    }
};