class Solution {
public:
    int maxDotProduct(vector<int>& a, vector<int>& b) {
        int n = b.size();
        int m = a.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1));
        for(int i = 0;i<dp.size();i++){
        for(int j = 0;j<dp[0].size();j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }
        }
        }
        for(int i = 1;i<dp.size();i++){
        for(int j = i;j<dp[0].size();j++){
            dp[i][j] = max(dp[i][j-1],(b[i-1]*a[j-1])+dp[i-1][j-1]);
        }
        }
        return dp[n][m];
    }
};
