class Solution {
public:
    bool helper(multiset<long double> st){
        if(st.size()==1){
            if(*st.begin()==24 || abs(*st.begin() - 24) < 1e-9)
                return true;
            else
                return false;
        }
        bool ans=0;
        vector<long double> values;
        for(auto i:st)values.push_back(i);

        for(int i=0;i<values.size();i++){
            for(int j=i+1;j<values.size();j++){
                multiset <long double> s = st;

                s.erase(s.find(values[i])); s.erase(s.find(values[j]));
                s.insert(values[i]+values[j]);
                ans|=helper(s);
                s.erase(s.find(values[i]+values[j]));
                s.insert(values[i]-values[j]);
                ans|=helper(s);
                s.erase(s.find(values[i]-values[j]));
                s.insert(values[j]-values[i]);
                ans|=helper(s);
                s.erase(s.find(values[j]-values[i]));
                s.insert(values[i]*values[j]);
                ans|=helper(s);
                s.erase(s.find(values[i]*values[j]));
                if(values[j]){
                    s.insert(values[i]/values[j]);
                    ans|=helper(s);
                    s.erase(s.find(values[i]/values[j]));
                }
                if(values[i]){
                    s.insert(values[j]/values[i]);
                    ans|=helper(s);
                }
            }
        }
            return ans;
    }
    bool judgePoint24(vector<int>& cards) {
        multiset<long double> st;
        for(auto i:cards)st.insert(i);
        return helper(st);
        
    }
};
