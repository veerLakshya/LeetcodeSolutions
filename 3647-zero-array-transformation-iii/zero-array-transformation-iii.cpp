class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), q = queries.size();
        sort(queries.begin(), queries.end(), [](const vector<int>& a, const vector<int>& b){
        return a[0] < b[0];
    });
        priority_queue<int> heap;
        vector<int> diff(n+1, 0);
        int cur = 0;
        for(int i = 0, j = 0; i < n; i++){
            cur += diff[i];
            while(j < q && queries[j][0] <= i){
                heap.push(queries[j][1]);
                j++;
            }
            while(cur < nums[i] && heap.size() && heap.top() >= i){
                cur += 1;
                diff[heap.top() + 1] -= 1;
                heap.pop();
            }
            if(cur < nums[i]) return -1;
        }
        return heap.size();
    }
};