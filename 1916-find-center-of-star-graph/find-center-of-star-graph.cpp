class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int N = 1e5+1;
        vector<int> deg(N,0);
        set<int> st;
        for(auto i : edges){
            st.insert(i[0]);
            st.insert(i[1]);
            deg[i[0]-1]++;
            deg[i[1]-1]++;
        }
        for(int i = 0; i < st.size()+1; i++) if(deg[i] == st.size() - 1) return i+1;
        return -1;
    }
};