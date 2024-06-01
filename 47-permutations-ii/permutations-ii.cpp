class Solution {
public:
    int n;
    set<vector<int>> st;
    vector<vector<int>> ans;
    void helper(vector<int>& temp, vector<int>& nums,vector<int>& visited){
        if(temp.size()==n ){
            if(!st.contains(temp)){
                st.insert(temp);
                ans.push_back(temp);
            }
            return;
        }
        for(int i=0;i<n;i++){
            if(visited[i])continue;
            temp.push_back(nums[i]);
            visited[i]=1;
            helper(temp,nums,visited);
            temp.pop_back();
            visited[i]=0;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n=nums.size();
        vector<int> temp;
        vector<int> visited(n,0);
        helper( temp,nums,visited);
        return ans;
    }
};