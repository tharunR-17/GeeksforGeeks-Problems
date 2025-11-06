class Solution {
    static int[] dp;
    public int numberOfWays(int n) {
      dp = new int[n + 1];  
      Arrays.fill(dp,-1);
      return solve(n);
    }
    public int solve(int n){
        if(n == 0) return 1;
        if(dp[n] != -1) return dp[n];
        return dp[n] =  ((n-1)>=0?solve(n-1):0) + ((n-2)>=0?solve(n-2):0);
    }
}
