class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_set<int> pos(arr.begin(),arr.end());
        int ans = 0, n = arr.size();
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int prev = arr[j];
                int cur = arr[j] + arr[i];
                int len = 2;
                while(pos.find(cur)!=pos.end()){
                    len++;
                    int temp = cur;
                    cur += prev;
                    prev = temp;
                    cout << prev << cur << temp << endl;
                    ans = max(ans, len);
                }
            }
        }
        return ans;
    }
};