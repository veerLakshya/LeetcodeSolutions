class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int f = flowers.size(), n = people.size();
        vector<int> ans(n);

        vector<pair<int,int>> queries; // time,ind
        for(int i = 0; i < n; i++) queries.push_back({people[i],i});
        sort(queries.begin(),queries.end());

        map<int,int> freq;
        for(auto i: flowers){
            freq[i[0]]++;
            freq[i[1] + 1]--;
        }

        int cur = 0, query_ind = 0;
        for(auto i: freq){
            int cur_pos = i.first;
            while(query_ind < queries.size() && queries[query_ind].first < cur_pos){
                ans[queries[query_ind].second] = cur;
                query_ind++;
            }
            cur += i.second;
        }
        return ans;
    }
};