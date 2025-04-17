class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> s;
        int x = 0;
        for(int i = 1; i <= n; i++){
            if(x < target.size() && i == target[x]){
                s.push_back("Push");
                x++;
            }
            else{
                s.push_back("Push");
                s.push_back("Pop");
            }
            if(x == target.size()) break;
        }
        return s;
    }
};