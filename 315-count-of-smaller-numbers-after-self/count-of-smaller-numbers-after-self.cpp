struct BIT{
    int size = 20069;
    vector<int> table;
    BIT(int x){
        table.resize(size);
    }
    void update(int x){
        while(x < size){
            table[x] += 1;
            x += x&(-x);
        }
    }
    int sum(int x){
        int ans = 0;
        while(x > 0){
            ans += table[x];
            x -= x&(-x);
        }
        return ans;
    }
    int cnt(int x){
        return sum(x-1);
    }
};
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        BIT b(0);
        vector<int> ans(nums.size(), 0);
        for(int i = nums.size() - 1; i >= 0; i--){
            ans[i] = b.cnt(nums[i] + 10005);
            b.update(nums[i] + 10005);
        }
        return ans;
    }
};