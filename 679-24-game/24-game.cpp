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
                // multiset<long double> temp = st;
                // temp.erase(temp.find(values[i]));
                // temp.erase(temp.find(values[j]));
                // temp.insert(values[i] + values[j]);
                // ans |= helper(temp);

                // temp = st;
                // temp.erase(temp.find(values[i]));
                // temp.erase(temp.find(values[j]));
                // temp.insert(values[i]*values[j]);
                // ans |= helper(temp);

                // temp = st;
                // temp.erase(temp.find(values[i]));
                // temp.erase(temp.find(values[j]));
                // temp.insert(values[i] - values[j]);
                // ans |= helper(temp);

                // temp = st;
                // temp.erase(temp.find(values[i]));
                // temp.erase(temp.find(values[j]));
                // temp.insert(values[j] - values[i]);
                // ans |= helper(temp);

                // temp = st;
                // temp.erase(temp.find(values[i]));
                // temp.erase(temp.find(values[j]));
                // if (values[j]) {
                //     temp.insert(values[i] / values[j]);
                //     ans |= helper(temp);
                // }

                // temp = st;
                // temp.erase(temp.find(values[i]));
                // temp.erase(temp.find(values[j]));
                // if (values[i]) {
                //     temp.insert(values[j] / values[i]);
                //     ans |= helper(temp);
                // }
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
/*
public:
        for (int i = 0; i < values.size(); i++) {
            for (int j = i + 1; j < values.size(); j++) {
                multiset<long double> temp = s;
                temp.erase(temp.find(values[i]));
                temp.erase(temp.find(values[j]));
                temp.insert(values[i] + values[j]);
                kitna |= fn(temp);

                temp = s;
                temp.erase(temp.find(values[i]));
                temp.erase(temp.find(values[j]));
                temp.insert(values[i]*values[j]);
                kitna |= fn(temp);

                temp = s;
                temp.erase(temp.find(values[i]));
                temp.erase(temp.find(values[j]));
                temp.insert(values[i] - values[j]);
                kitna |= fn(temp);

                temp = s;
                temp.erase(temp.find(values[i]));
                temp.erase(temp.find(values[j]));
                temp.insert(values[j] - values[i]);
                kitna |= fn(temp);

                temp = s;
                temp.erase(temp.find(values[i]));
                temp.erase(temp.find(values[j]));
                if (values[j]) {
                    temp.insert(values[i] / values[j]);
                    kitna |= fn(temp);
                }

                temp = s;
                temp.erase(temp.find(values[i]));
                temp.erase(temp.find(values[j]));
                if (values[i]) {
                    temp.insert(values[j] / values[i]);
                    kitna |= fn(temp);
                }
            }
        }
        return kitna;
    }
    bool judgePoint24(vector<int>& cards) {
        multiset<long double> s;
        for (auto i : cards) s.insert(i);
        fn(s);
        if(saare.find(24)!=saare.end()) return 1;
        return 0;
    }
};
*/