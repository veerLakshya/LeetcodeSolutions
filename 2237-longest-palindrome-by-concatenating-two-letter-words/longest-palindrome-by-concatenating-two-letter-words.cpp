class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string,int> mpdif, mpsame;
        for(auto i: words){
            if(i[0] == i[1]) mpsame[i]++;
            else mpdif[i]++;
        }
        int ans = 0;
        for(auto i: mpdif){
            string rev = i.first;
            swap(rev[0],rev[1]);
            if(mpdif.find(rev) != mpdif.end()){
                ans += 4*min(i.second, mpdif[rev]);
                mpdif.erase(rev);
            }
        }
        bool f = 0;
        for(auto i: mpsame){
            if(i.second%2 == 1 && !f){
                f = 1;
                ans += 4*(i.second/2);
            }
            else{
                ans += 4*(i.second/2);
            }
        }
        if(f) ans += 2;
        return ans;
    }
};