class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        long long total = accumulate(skill.begin(),skill.end(), 0LL);
        // if(total&1 && n>2) return -1;
        long long target = total * 2 / n;

        multiset <long long> st;
        for(auto i: skill) st.insert(i);

        long long ans = 0;

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
        cout<<ans;
        if(st.size()) return -1;
        return ans;
    }
};