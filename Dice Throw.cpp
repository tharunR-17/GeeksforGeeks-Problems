class Solution {
  public:
    int solve(int n,int &m,int x, vector<vector<vector<int>>>&dp)
    {
      if(n==0 && x==0)
      {
          return 1;
      }
      if(n==0 || x<0)
      {
          return 0;
      }
      if(dp[n][m][x]!=-1)
      {
          return dp[n][m][x];
      }
      int ans=0;
      for(int i=1;i<=m;i++)
      {
         ans+=solve(n-1,m,x-i,dp); 
      }
      return dp[n][m][x]=ans;
    }
    int noOfWays(int m, int n, int x) {
        // code here
        vector<vector<vector<int>>>dp;
        dp.assign(n+1,vector<vector<int>>(m+1,vector<int>(x+1,-1)));
        return solve(n,m,x,dp);
    }
};
