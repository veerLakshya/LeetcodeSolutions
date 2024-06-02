class Solution {
public:
    int n;
    vector<vector<int>> combinations;
    vector<int> currSubset;
    void backtrack(int index, int target,vector<int>& candidates){
        if(target==0){
            combinations.push_back(currSubset);
            return;
        }
        if(index==candidates.size()||target<0)return;
        backtrack(index+1,target,candidates);
        currSubset.push_back(candidates[index]);
        backtrack(index,target-candidates[index],candidates);
        currSubset.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
       backtrack(0,target,candidates);
       return combinations;
    }
};