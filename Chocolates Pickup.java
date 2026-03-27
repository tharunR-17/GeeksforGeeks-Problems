class Solution 
{
    int[][] grid;
    int[][][] dp;
    
    public int solve(int i,int j1,int j2)
    {
        int n=grid.length;
        int m=grid[0].length;
        
        if(j1<0 || j2<0 || j1>=m || j2>=m)return Integer.MIN_VALUE/2;
        if(i==n)return 0;
        
        if(dp[i][j1][j2]!=-1)return dp[i][j1][j2];
        
        int ans=0;
        int chocolates=(j1==j2)?(grid[i][j1]):(grid[i][j1]+grid[i][j2]);
        
        ans=Math.max(ans,solve(i+1,j1-1,j2-1));
        ans=Math.max(ans,solve(i+1,j1-1,j2));
        ans=Math.max(ans,solve(i+1,j1-1,j2+1));
        
        ans=Math.max(ans,solve(i+1,j1,j2-1));
        ans=Math.max(ans,solve(i+1,j1,j2));
        ans=Math.max(ans,solve(i+1,j1,j2+1));
        
        ans=Math.max(ans,solve(i+1,j1+1,j2-1));
        ans=Math.max(ans,solve(i+1,j1+1,j2));
        ans=Math.max(ans,solve(i+1,j1+1,j2+1));
        
        return dp[i][j1][j2]=ans+chocolates;
    }
    public int maxChocolate(int grid[][]) {
        // code here
        this.grid=grid;
        int n=grid.length;
        int m=grid[0].length;
        
        dp=new int[n][m][m];
        for(int[][] mat:dp)for(int[] row:mat)Arrays.fill(row,-1);
        
        return solve(0,0,m-1);
    }
}
