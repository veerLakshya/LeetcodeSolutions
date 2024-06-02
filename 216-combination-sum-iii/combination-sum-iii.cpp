class Solution {
public:
    vector<vector<int>> ans;
    vector<int> current;
    void helper(int start, int cnt_elements, int left_sum){
        if( left_sum == 0 && cnt_elements == 0 ){
            ans.push_back(current);
            return;
        }
        if( cnt_elements < 0 || left_sum < 0 || start > 9 ) return;
        helper( start + 1, cnt_elements, left_sum );
        cnt_elements--;
        current.push_back(start);
        helper( start + 1, cnt_elements, left_sum-start );
        cnt_elements++;
        current.pop_back();
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        helper( 1, k, n );
        return ans;
    }
};