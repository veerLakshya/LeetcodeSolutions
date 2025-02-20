class Solution {
public:
    set<string> st;
    int n;
    string ans;
    bool h(string cur){
        if(cur.size() == n) {
            if(st.find(cur) != st.end()) return false;
            else{
                ans = cur;
                return true;
            } 
        }
        return h(cur + '0') | h(cur + '1');
    }
    string findDifferentBinaryString(vector<string>& nums) {
        for(auto i: nums)st.insert(i);
        n = nums[0].size();
        h("");
        return ans;
    }
};