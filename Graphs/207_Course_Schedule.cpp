class Solution {
public:
    bool dfs(int v, vector<int>& vis, vector<int>& pathVis,
             vector<vector<int>>& adj) {
        vis[v] = 1;
        pathVis[v] = 1;
        for(auto it : adj[v]) {
            if(!vis[it]) {
                if(dfs(it, vis, pathVis, adj))
                    return true;
            }
            else if(pathVis[it]) {
                return true;
            }
        }
        pathVis[v] = 0;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto p : prerequisites) {
            adj[p[1]].push_back(p[0]);
        }
        vector<int> vis(numCourses, 0);
        vector<int> pathVis(numCourses, 0);
        for(int i = 0; i < numCourses; i++) {
            if(!vis[i]) {
                if(dfs(i, vis, pathVis, adj))
                    return false;
            }
        }
        return true;
    }
};
