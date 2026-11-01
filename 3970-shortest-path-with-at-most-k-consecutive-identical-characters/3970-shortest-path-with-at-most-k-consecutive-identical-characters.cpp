
class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        if (k < 1) return -1;
        if (n == 1) return 0;

        vector<vector<pair<int, int>>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }

        const long long INF = 1e18;
        vector<vector<long long>> dist(n, vector<long long>(k + 1, INF));

        priority_queue<tuple<long long, int, int>, 
                       vector<tuple<long long, int, int>>, 
                       greater<tuple<long long, int, int>>> pq;

        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {
            auto [d, u, c] = pq.top();
            pq.pop();

            if (d > dist[u][c]) continue;
            if (u == n - 1) return d;

            for (const auto& [v, w] : adj[u]) {
                int next_c = (labels[v] == labels[u]) ? (c + 1) : 1;

                if (next_c <= k && d + w < dist[v][next_c]) {
                    dist[v][next_c] = d + w;
                    pq.push({dist[v][next_c], v, next_c});
                }
            }
        }

        return -1;
    }
};