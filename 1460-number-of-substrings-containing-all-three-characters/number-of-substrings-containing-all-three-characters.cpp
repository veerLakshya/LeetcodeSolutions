class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> freq(26, 0);
        long long ans = 0;
        int right = 0;
        for(int i = 0; i < n; i++){
            while(right < n && (!freq[0] || !freq[1] || !freq[2])){
                freq[s[right] - 'a']++;
                right++;
            }
            if(freq[0] && freq[1] && freq[2]) ans += (n-right + 1);
            freq[s[i]-'a']--;
        }
        return ans;
    }
};