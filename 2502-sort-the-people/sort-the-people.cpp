class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int, string> mp;

        for(int i=0;i<heights.size();i++){
            mp[heights[i]]=names[i];
        }
        int t=0;
        for(auto i:mp){
            heights[t]=i.first;
            names[t]=i.second;
            t++;
        }
        reverse(names.begin(), names.end());
        return names;
        
    }
};