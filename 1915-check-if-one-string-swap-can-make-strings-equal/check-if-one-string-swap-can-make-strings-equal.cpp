class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        pair<int,int> ps1 = {-1,-1};
        for(int i = 0; i < s1.size(); i++){
            if(s1[i] != s2[i]){
                if(ps1.first == -1) ps1.first = i;
                else ps1.second = i;
            }
        }
        if(ps1.first != -1 && ps1.second != -1) swap(s1[ps1.first], s1[ps1.second]);
        // cout << ps1.first << " "<<ps1.second<<endl;
        // cout<<s1 << " "<<s2;
        return s1 == s2;
    }
};