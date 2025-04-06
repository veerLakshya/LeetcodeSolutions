class MiddleElement {
public:
    long long leftsize;
    long long sum = 0;
    multiset<long long> left, right;
    MiddleElement(long long k) { leftsize = k; }
    void balance() {
        while (left.size() < leftsize && left.size() && right.size()) {
            int temp = *right.begin();
            sum += temp;
            left.insert(temp);
            right.erase(right.find(temp));
        }
        while (left.size() > leftsize) {
            int temp = *left.rbegin();
            sum -= temp;
            right.insert(temp);
            left.erase(left.find(temp));
        }
    }
    void insert(int x) {
        if (x < *left.rbegin()) {
            left.insert(x);
            sum += x;
        } else
            right.insert(x);
        balance();
    }
    void erase(int x) {
        auto it = right.find(x);
        if (it != right.end())
            right.erase(it);
        else {
            sum -= x;
            left.erase(left.find(x));
        }
        balance();
    }
};
class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        long long ans = 1e18, n = nums.size();
        k--; // as we take first element in first subarray;
        MiddleElement ds(k);
        for(int i = 1; i <= k && i < n; i++){
            ds.left.insert(nums[i]);
            ds.sum += nums[i];
        }
        ans = min(ans, ds.sum);
        for(int i = k + 1; i < n; i++){
            if(ds.left.size() + ds.right.size() >= dist + 1){
                ds.erase(nums[i - (dist + 1)]);
            }
            ds.insert(nums[i]);
            ans = min(ans, ds.sum);
        }
        return nums[0] + ans;
    }
};