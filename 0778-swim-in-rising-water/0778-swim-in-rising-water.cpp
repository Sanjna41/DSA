class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({grid[0][0],{0,0}});
        dist[0][0] = grid[0][0];
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1}; 
        
        while(!pq.empty()){
            
            int t = pq.top().first;
            int u = pq.top().second.first;
            int v = pq.top().second.second;
            pq.pop();
            
            
            if(u == n-1 && v==n-1) return t;
            if(t>dist[u][v]) continue;
            for(int i=0;i<4;i++){
                int nr = u+dr[i];
                int nc = v+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<n  ){
                    int newtime = max(t,grid[nr][nc]);
                    if(newtime<dist[nr][nc]){
                        dist[nr][nc] = newtime;
                        pq.push({newtime,{nr,nc}});
                    }
                    
                }
            }

        }
        return 0;

    }
};