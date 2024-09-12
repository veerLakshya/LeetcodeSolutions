class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int ans = 0;
        int arr[26] = {0};
        for(auto i: allowed) arr[i-'a']++;

        for(auto word: words){
            bool f = true;
            for(auto i: word){
                if(arr[i - 'a'] == 0){
                    f = 0;
                    break;
                }
            }
            if(f) ans++;
        }
        return ans;
    }
};