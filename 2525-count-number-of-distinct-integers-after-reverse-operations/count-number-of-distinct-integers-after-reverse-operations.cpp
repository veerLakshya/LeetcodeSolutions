class Solution {
public:
    int reverseDigits(int num) 
    { 
        int rev_num = 0; 
        while (num > 0) { 
            rev_num = rev_num * 10 + num % 10; 
            num = num / 10; 
        } 
        return rev_num; 
    } 
    int countDistinctIntegers(vector<int>& nums) {
        set <int> st;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
            st.insert(reverseDigits(nums[i]));
        }
        return st.size();
    }
};