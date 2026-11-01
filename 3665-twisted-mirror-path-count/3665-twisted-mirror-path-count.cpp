#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        const int MOD = 1e9 + 7;
        auto getNext = [&](int r, int c, int dir) -> pair<int, int> {
            int cr = r, cc = c, cdir = dir;
            while (true) {
                if (cdir == 0) {
                    cc++;
                } else {
                    cr++;
                }
                if (cr >= m || cc >= n) return {-1, -1};
                if (grid[cr][cc] == 0) {
                    return {cr, cc};
                }
                cdir ^= 1;
            }
        };

        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (dp[r][c] == 0 || grid[r][c] == 1) continue;

                long long currentWays = dp[r][c];

                auto [r1, c1] = getNext(r, c, 0);
                if (r1 != -1 && c1 != -1) {
                    dp[r1][c1] = (dp[r1][c1] + currentWays) % MOD;
                }

               auto [r2, c2] = getNext(r, c, 1);
                if (r2 != -1 && c2 != -1) {
                    dp[r2][c2] = (dp[r2][c2] + currentWays) % MOD;
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};