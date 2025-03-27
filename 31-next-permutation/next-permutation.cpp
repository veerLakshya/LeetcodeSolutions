class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        bool flag = 1;
        for(int i = nums.size() - 1; i > 0; i--){
            if(nums[i] > nums[i-1]){
                cout << i << endl;
                flag = 0;
                sort(nums.begin() + i, nums.end());
                for(int j = i; j < nums.size(); j++){
                    if(nums[j] > nums[i - 1]){
                        swap(nums[j], nums[i - 1]);
                        break;
                    }
                }
                break;
            }
        }
        if(flag){
            int i = 0, j = nums.size() - 1;
            while(i < j){
                swap(nums[i], nums[j]);
                i++,j--;
            }
        }
    }
};