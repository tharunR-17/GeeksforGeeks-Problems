class Solution {
    int n;
  public:
    int solve(vector<int> &cost, int buy, int idx, vector<vector<int>> &dp) {
        if(buy == 0)
            return 0;
            
        if(buy < 0)
            return INT_MAX;
            
        if(idx >= n)
                return INT_MAX;
        
        if(dp[buy][idx] != -1)
            return dp[buy][idx];
            
        if(cost[idx] == -1)
            return solve(cost, buy, idx + 1, dp);
            
        int addNext = solve(cost, buy - idx - 1, idx + 1, dp);
        int addSame = solve(cost, buy - idx - 1, idx, dp);
        
        if(addNext != INT_MAX)
            addNext += cost[idx];
        if(addSame != INT_MAX)
            addSame += cost[idx];
            
        int moveNext = solve(cost, buy, idx + 1, dp);
        
        return dp[buy][idx] = min(addNext, min(addSame, moveNext));
    }
    int minimumCost(vector<int> &cost, int w) {
        // code here
        n = cost.size();
        
        vector<vector<int>> dp(w + 1, vector<int>(n + 1, -1));
        
        int res = solve(cost, w, 0, dp);
        
        return res == INT_MAX ? -1 : res;
    }
};
