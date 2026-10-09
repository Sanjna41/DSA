class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>> dist(n + 1, vector<int>(n + 1, 1e9));

        for (int i = 1; i <= n; i++) {
            dist[i][i] = 0;
        }

        for (const auto& it : times) {
            dist[it[0]][it[1]] = it[2];
        }

        for (int via = 1; via <= n; via++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (dist[i][via] != 1e9 && dist[via][j] != 1e9) {
                        dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
                    }
                }
            }
        }

        int max_time = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[k][i] == 1e9) return -1; 
            max_time = max(max_time, dist[k][i]);
        }

        return max_time;
    }
};