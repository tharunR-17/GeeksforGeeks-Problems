class Solution {
  public:
    int count(int i,int n,vector<vector<int>>&numpad,vector<vector<int>>&dp)
    {
        if(n<=0)
        return 1;
        if(dp[i][n]!=-1)
        return dp[i][n];
        int cnt=0;
        for(auto it:numpad[i])
        {
            cnt+=count(it,n-1,numpad,dp);
        }
        return dp[i][n] = cnt;
    }
    int getCount(int n) {
        vector<vector<int>>numpad={{0,8},{1,2,4},{2,1,3,5},{3,2,6},{4,1,5,7},{5,2,4,6,8},{6,3,5,9},{7,4,8},{8,5,7,9,0},{9,6,8}};
        int ans = 0;
        int x = 0;
        vector<vector<int>>dp(10,vector<int>(n,-1));
        for(int i=0;i<=9;i++)
        {
            x = count(i,n-1,numpad,dp);
            // cout<<i<<" "<<x<<endl;
            ans += x;
        }
        return ans;
    }
};
