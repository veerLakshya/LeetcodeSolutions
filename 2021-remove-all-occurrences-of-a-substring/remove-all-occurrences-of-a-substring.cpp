class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(s.find(part) != string::npos){
            int ind = s.find(part);
            s = s.substr(0, ind) + s.substr(ind + part.size());
        }
        return s;
    }
};