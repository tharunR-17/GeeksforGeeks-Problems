class Solution {
public:
    int maxGold(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> dp(2, vector<int>(n, 0)); // 2 rows only

        for (int i = 0; i < n; i++) {
            dp[0][i] = mat[i][0];
        }

        for (int j = 1; j < m; j++) {
            for (int i = 0; i < n; i++) {
                int right = dp[(j - 1) % 2][i];
                int right_up = (i > 0) ? dp[(j - 1) % 2][i - 1] : 0;
                int right_down = (i < n - 1) ? dp[(j - 1) % 2][i + 1] : 0;

                dp[j % 2][i] = mat[i][j] + max({right, right_up, right_down});
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, dp[(m - 1) % 2][i]);
        }

        return ans;
    }
};
