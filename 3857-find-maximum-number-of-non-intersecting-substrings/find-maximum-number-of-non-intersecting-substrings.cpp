class Solution {
public:
    int maxSubstrings(string word) {
        int n = word.size();
        map<char,int> mp, t;
        // int last = -1;
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(mp.find(word[i]) != mp.end()){
                int prev = mp[word[i]];
                if(i-prev+1 >= 4){
                    ans++;
                    for(auto i: mp) cout << i.first << " ";
                    cout << endl;
                    mp = t;
                }
            }
            else mp[word[i]]=i;
        }

        return ans;
    }
};