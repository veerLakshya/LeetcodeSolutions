class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();
        double waiting_time = customers[0][1];
        int prev_finished = customers[0][0]+ customers[0][1];
        
        for(int ind = 1; ind<n; ind++){
            vector<int> times = customers[ind];
            int arrive = times[0];

            int start = max(arrive,prev_finished);
            int end = start + times[1];
            prev_finished = end;
            waiting_time += end - arrive;
        }
        return waiting_time/n;
    }
};