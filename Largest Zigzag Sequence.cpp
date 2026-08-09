class Solution {
  public:
    
    int solve(int i, int j, vector<vector<int>>& mat, vector<vector<int>>& dp) {
        
        if (i == mat.size()-1) {
            return mat[i][j];
        }
        
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int best = 0;
        
        for (int k=0; k<mat.size(); k++) {
            
            if (k != j) {
                best = max(best, solve(i+1, k, mat, dp));
            }
        }
        
        return dp[i][j] =  mat[i][j] + best;
    }
    int zigzagSequence(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        // vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for (int j=0; j<n; j++) {
            dp[0][j] = mat[0][j];
        }
        
        for (int i=1; i<n; i++) {
            
            for (int j=0; j<n; j++) {
                int best = 0;
                
                for (int k=0; k<n; k++) {
                    
                    if (k == j) continue;
                    
                    best = max(best, dp[i-1][k]);
                }
                
                dp[i][j] = mat[i][j] + best;
            }
            
        }
        // int ans = 0;
        
        // for (int j=0; j<n; j++) {
        //     ans = max(ans, solve(0, j, mat, dp));
        // }
        
        // return ans;
        
        return *max_element(dp[n-1].begin(), dp[n-1].end());
    }
};
