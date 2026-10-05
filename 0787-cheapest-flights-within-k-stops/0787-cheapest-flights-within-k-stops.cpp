class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i=0;i<flights.size();i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int pr = flights[i][2];
            adj[u].push_back({v,pr});

        }
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});
        vector<int> dis(n, 1e9);
        dis[src] =0;
        while(!q.empty()){
            auto it= q.front();
            int stops = it.first;
            int v = it.second.first;
            int dist = it.second.second;
            q.pop();
            if(stops>k) continue;
            for(auto i: adj[v]){
                int adjN = i.first;
                int edge = i.second;
                if(dist+edge < dis[adjN] && stops<=k){
                    dis[adjN] = dist+edge;
                    q.push({stops+1,{adjN,dist+edge}});
                }
            }

        }
        if(dis[dst] == 1e9) return -1;
        return dis[dst];


    }
};