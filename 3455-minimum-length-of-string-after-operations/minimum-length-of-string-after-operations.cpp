class Solution {
public:
    int minimumLength(string s) {
        vector<int> freq(26,0);
        for(auto i: s)freq[i -'a']++;
        for(int i = 0; i < 26; i++){
            if(freq[i] & 1) freq[i] = 1;
            else if( freq[i] > 0) freq[i] = 2;
        }
        return accumulate(freq.begin(), freq.end(), 0);
    }
};