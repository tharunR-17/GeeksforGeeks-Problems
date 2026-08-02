class Solution {
  public:
    virtual int svc(int i, int prev, int n, int m, vector<vector<int>> &dp){
      if(i==n) return 1;
      
      if(prev!=-1 && dp[i][prev] != -1) return dp[i][prev];
      
      
      int t=0;
      for(int k=1; k<=m; k++){
        if(prev==-1) t+=svc(i+1, k, n, m, dp);
        else if(prev%k==0 || k%prev==0) t+=svc(i+1, k, n, m, dp);  
      }
      
      if(prev==-1) return t;
      return dp[i][prev] = t;      
    }
    
    virtual int count(int n, int m){
      vector<vector<int>> dp(n+1, vector<int>(m+1, -1));    
      return svc(0, -1, n, m, dp);
    }
};
