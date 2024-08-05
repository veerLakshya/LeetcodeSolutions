class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        map<string,int> mp;
        for(auto i: arr) mp[i]++;
        int cnt = 0;
        // vector<string> anss;
        for(auto i: arr){
            if(mp[i]==1){
                if(++cnt == k) return i;
            }
        }
        return "";
    }
};