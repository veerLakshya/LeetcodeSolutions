class Solution {
public:
    int minimumPushes(string word) {
        vector<int> arr(26);
        for(auto i: word) arr[i-'a']++;
        sort(arr.rbegin(),arr.rend());
        int ans = 0, cnt = 0;
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