class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int> val;
        for(int i = 0; i < order.size(); i++){
            val[order[i]] = i;
        }
        sort(s.begin(),s.end(),[&](char a, char b){
            return val[a] < val[b];
        });
        return s;
    }
};