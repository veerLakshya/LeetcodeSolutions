class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> left,right;
        for(auto i:nums) 
            if(i < pivot) left.push_back(i);
            else if(i > pivot) right.push_back(i);
        for(auto i: nums) if(i == pivot) left.push_back(i);
        for(auto i: right) left.push_back(i);
        return left;
    }
};