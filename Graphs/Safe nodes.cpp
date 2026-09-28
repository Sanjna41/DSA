class Solution {
public:
    bool dfs(int node,vector<int>& vis,vector<int>& path,vector<int>& check ,vector<vector<int>>& graph){
        vis[node] =1;
        path[node] =1;
        check[node] =0;
        for(auto it : graph[node]){
            if(!vis[it]){
                if(dfs(it,vis,path,check,graph)){
                     check[it] =0;
                     return true;
                }
            }
             if(path[it]){
                    check[it] =0;
                    return true;
                    
                }
        }
        check[node] =1;
        path[node] =0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
         vector<int> path(n,0);
         vector<int> vis(n,0);
         vector<int> check(n,0);
         vector<int> safe;
         for(int i=0;i<n;i++){
              if(!vis[i]){
                 dfs(i,vis,path,check,graph);
              }
         } 
         for(int i =0;i<n;i++){
             if(check[i] ==1) safe.push_back(i);
         }
        return safe;
    }
};
