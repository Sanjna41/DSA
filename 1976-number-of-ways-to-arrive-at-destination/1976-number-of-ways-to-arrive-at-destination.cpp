class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> adj[n];
        for(auto it: roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        pq.push({0,0});
        vector<long long> dis(n,1e18);
        vector<int> ways(n,0);
        dis[0] = 0;
        ways[0] =1;
        int mod = 1e9+7;
        while(!pq.empty()){
            long long dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(dist> dis[node]) continue;
            for(auto it: adj[node]){
                int adjN = it.first;
                long long wt = it.second;
                if( dist+wt < dis[adjN]){
                    dis[adjN] = dist+wt;
                    pq.push({dist+wt, adjN});
                    ways[adjN] = ways[node];
                }
                else if( dist + wt == dis[adjN]){
                    ways[adjN] = (ways[adjN] + ways[node]) % mod;

                }
            }

        }
        return ways[n-1] ;
    }
};