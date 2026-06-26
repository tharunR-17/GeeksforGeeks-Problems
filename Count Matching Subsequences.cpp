class Solution {
public:
    int countWays(string &s1, string &s2) {
        //bhagwan pls pass the testcases this time.
        //jai bajrang bali , jai shree ram.
        //let's start.
        long long MOD = 1000000007;
        int n = s2.length();
        int m = s1.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1));
        for(int i = 0;i<dp.size();i++){
        for(int j = 0;j<dp[0].size();j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }
        }
        }
        int cnt = 0;
        for(int j = 1;j<dp[0].size();j++){
            if(s2[0] == s1[j-1]){
                cnt++;
            }
            dp[1][j] = cnt;
        }
        for(int i = 2;i<dp.size();i++){
            int cnt = 0;
        for(int j = 1;j<dp[0].size();j++){
            if(s2[i-1] == s1[j-1]){
                cnt = ((cnt%MOD) + (dp[i-1][j-1]%MOD))%MOD;
                dp[i][j] = cnt;
            }
            else{
                dp[i][j] = dp[i][j-1];
            }
        }
        }
        return dp[n][m];
    }
};
