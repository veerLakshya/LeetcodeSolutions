class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        vector<int> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<queries.size();i++){
            int sum=0;
            int cnt=0;
            for(int j=0;j<nums.size();j++){
                if(sum+nums[j]<=queries[i]){
                sum+=nums[j];
                cnt++;
                }
                else{
                    ans.push_back(cnt);
                    break;
                }
                // cout<<sum<<" "<<cnt<<" |";
            }
            if(ans.size()!=i+1)ans.push_back(nums.size());
            cout<<endl;
        }
        return ans;
        
    }
};