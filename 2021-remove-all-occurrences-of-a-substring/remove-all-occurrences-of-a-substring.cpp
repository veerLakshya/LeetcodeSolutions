class Solution {
public:
    string removeOccurrences(string s, string part) {
        string ans = "";
        int n = s.size(), m = part.size();
        for(int i = 0; i < n; i++){
            ans += s[i];
            if(ans.size() >= m){
                string temp = ans;
                int j = m - 1;
                int k = ans.size() - 1;
                while(j >= 0 && k >= 0 && part[j] == temp[k]){
                    temp.pop_back();
                    j--;
                    k--;
                }
                if(j < 0) ans = temp;
            }
        }
        return ans;
    }
};