class Solution {
public:
set<double> saare;
    bool fn(multiset<long double>s) {
        if (s.size() == 1){
            saare.insert(*s.begin());
            return 1;
        }
        vector<long double> values;
        bool kitna = false;
        for (auto i : s) values.push_back(i);
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