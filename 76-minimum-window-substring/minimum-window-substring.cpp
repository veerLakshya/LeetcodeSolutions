class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() > s.size()) return "";

        map<char,int> req;
        for(auto i: t) req[i]++;

        int left = 0, right = 0;
        int n = s.size(), cnt = t.size();
        int ans = INT_MAX, start_ind = 0;

        while(left < n){
            while(right < n && cnt){
                if(req[s[right]] > 0){
                    cnt--;
                }
                req[s[right]]--;
                right++;
            }
            if(!cnt){
                if(ans > right - left){
                    ans = right - left;
                    start_ind = left;
                }
            }
            req[s[left]]++;
            if(req[s[left]] > 0){
                cnt++;
            } 
            left++;
        }
        return (ans == INT_MAX ? "" : s.substr(start_ind, ans));
    }
};