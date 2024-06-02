class Solution {
public:
    vector<vector<int>> all_ans;
    vector<int> ans;
    int N,K;
    void helper(int x, int cnt){
        if(cnt==K){
            all_ans.push_back(ans);
            return;
        }
        for(int i=x;i<=N;i++){
            cnt++;
            ans.push_back(i);
            helper(i+1,cnt);
            ans.pop_back();
            cnt--;
        }
    }
    vector<vector<int>> combine(int n, int k) {
        N=n;
        K=k;
        helper(1,0);
        return all_ans;
    }
};