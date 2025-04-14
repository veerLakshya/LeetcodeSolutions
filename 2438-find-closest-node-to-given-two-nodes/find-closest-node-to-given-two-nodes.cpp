class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> d1(n, 1e9), d2(n, 1e9);

        queue<int> q;

        q.push(node1);
        d1[node1] = 0;
        while(q.size()){
            int cur =  q.front();
            q.pop();
            int nbr = edges[cur];
            if(nbr != -1 && d1[cur] + 1 < d1[nbr]){
                d1[nbr] = min(d1[cur] + 1, d1[nbr]);
                q.push(nbr);
            }
        }
        
        q.push(node2);
        d2[node2] = 0;
        while(q.size()){
            int cur =  q.front();
            q.pop();
            int nbr = edges[cur];
            if(nbr != -1 && d2[cur] + 1 < d2[nbr]){
                d2[nbr] = min(d2[cur] + 1, d2[nbr]);
                q.push(nbr);
            }
        }
        int ans = 1e9, node = -1;
        for(int i = 0; i < n; i++){
            // cout << d1[i] << " "<< d2[i]<<endl;
            if(max(d1[i],d2[i]) < ans){
                ans = max(d1[i],d2[i]);
                node = i;
            }
        }
        return node;
    }
};