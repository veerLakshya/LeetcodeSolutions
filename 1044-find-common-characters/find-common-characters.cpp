class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> ans;
        for (int i = 0; i < words[0].size(); i++) {
            bool flag = 1;
            char c = words[0][i];
            for (int j = 1; j < words.size(); j++) {
                string str = words[j];
                if (str.find(c) != std::string::npos) {
                    words[j][str.find(c)] = '*';
                } else {
                    flag=0;
                    break;
                }
            }
            if (flag) {
                string curr = "";
                curr += c;
                ans.push_back(curr);
            }
        }
        return ans;
    }
};