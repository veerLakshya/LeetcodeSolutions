class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        multiset <long long> st;
        for(auto i: skill) st.insert(i);

        long long ans = 0;
        long long target = accumulate(skill.begin(),skill.end(), 0LL) * 2 / skill.size();

        for(auto i: skill){
            if(st.find(i)!=st.end()){
                st.erase(st.find(i));
                long long req = target - i;
                if(st.find(req) != st.end()){
                    ans += (i*req);
                    st.erase(st.find(req));
                }
                else
                    st.insert(i);
            }
        }
        if(st.size()) return -1;
        return ans;
    }
};