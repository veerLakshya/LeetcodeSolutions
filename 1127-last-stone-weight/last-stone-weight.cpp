class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        while(stones.size()>1){
            int n=stones.size();
        sort(stones.begin(),stones.end());
            int t = stones[n-1]-stones[n-2];
            stones.pop_back();
            stones.pop_back();
            if(t)stones.push_back(t);
        }
        return stones.size()?stones[0]:0;
    }
};