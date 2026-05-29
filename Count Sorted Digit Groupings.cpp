class Solution {
public:
    vector<vector<int>> dp;
    int solve(string& s, int ind, int minSum) {
        if (ind >= s.size())
            return 1;
        if (dp[ind][minSum] != -1)
            return dp[ind][minSum];
        int res = 0;
        int sum = 0;
        for (int j = ind; j < s.size(); j++) {
            sum += s[j] - '0';
            if (sum >= minSum)
                res += solve(s, j + 1, sum);
        }
        return dp[ind][minSum] = res;
    }
    int validGroups(string& s) {
        dp = vector<vector<int>>(s.size() + 1, vector<int>(9 * s.size() + 1, -1));
        return solve(s, 0, 0);
    }
};
