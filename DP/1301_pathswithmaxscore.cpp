#include<bits/stdc++.h>
class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        dp[0][0] = grid[0][0];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 && j == 0) continue;
                int fromLeft = (j > 0) ? dp[i][j-1] : INT_MIN;
                int fromTop  = (i > 0) ? dp[i-1][j] : INT_MIN;
                dp[i][j] = grid[i][j] + max(fromLeft, fromTop);
            }
        }
        return dp[n-1][m-1];
    }

    int uniquePaths(int n, int m) {
        vector<vector<int>> dp(n, vector<int>(m, 1));  //imp point
        for (int i = 1; i < n; i++)
            for (int j = 1; j < m; j++)
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
        return dp[n-1][m-1];
    }

    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size(), 
            m = grid[0].size();
        vector<vector<long long>> dp(n, vector<long long>(m, 0));
        dp[0][0] = grid[0][0] == 1 ? 0 : 1;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (i == 0 && j == 0) continue;
                if (grid[i][j] == 1) { dp[i][j] = 0; continue; }
                long long fromTop = i > 0 ? dp[i-1][j] : 0;
                long long fromLeft = j > 0 ? dp[i][j-1] : 0;
                dp[i][j] = fromTop + fromLeft;
            }
        return (int)dp[n-1][m-1];
    }
};