class Solution {
public:
    string clearStars(string s) {
        int n = s.size();
        vector<int> removed;
        priority_queue<char, vector<char>, greater<char>> pq;
        map<char, vector<int>> mp;
        for(int i = 0; i < n; i++){
            if(s[i] == '*'){
                char c = pq.top();
                pq.pop();
                int l = mp[c].back();
                mp[c].pop_back();
                s[l] = '*';
            }
            else {
                pq.push(s[i]);
                mp[s[i]].push_back(i);
            }
        }
        string ans = "";
        for(auto i: s) if(i != '*') ans += i;
        return ans;
    }
};