class Solution {
public:
    int minimumPushes(string word) {
        vector<int> arr;
        map<char,int> mp;
        for(auto i: word) mp[i]++;
        for(auto i: mp) arr.push_back(i.second);
        int ans = 0;
        if(arr.size()<= 8){
            return word.size();
            return 0;
        }
        sort(arr.rbegin(),arr.rend());
        int cnt = 0;
        for(auto i: arr){
            cnt++;
            if(cnt<=8) ans+=i;
            else if(cnt<=16) ans+= 2*i;
            else if(cnt<= 24) ans+= 3*i;
            else ans+= 4*i;
        }
        return ans;
    }
};