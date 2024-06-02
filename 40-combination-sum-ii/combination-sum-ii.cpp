class Solution {
public:
    vector<int> curr_ans;
    vector<vector<int>> all_ans;
    int freq[51];
    void backtrack(int index, int target){
        if(target==0){
            all_ans.push_back(curr_ans);
            return;
        }
        if(index==51 || target<index)return;
        backtrack(index+1,target);
        if(freq[index]){
            freq[index]--;
            curr_ans.push_back(index);
            backtrack(index,target-index);
            curr_ans.pop_back();
            freq[index]++;
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        for(auto &i:candidates)freq[i]++;
        backtrack(1,target);
        return all_ans;
    }
};
/*
class Solution {
public:
    int k,n;
    set<vector<int>> s;
    vector<vector<int>> all_ans;
    vector<int> ans;
    void f(int start,int curr_sum,vector<int>arr){
        if(curr_sum==k){
            sort(ans.begin(),ans.end());
            s.insert(ans);
            return;
        }
        if(curr_sum>k|| start==n)return;
        for(int i=start;i<n;i++){
            // curr_sum+=arr[i];
            ans.push_back(arr[i]);
            f(i+1,curr_sum+arr[i],arr);
            ans.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        n=candidates.size();
        k=target;
        f(0,0,candidates);
        for(auto i:s)all_ans.push_back(i);
        return all_ans;
    }
};
*/