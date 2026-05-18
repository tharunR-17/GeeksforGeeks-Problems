class Solution {
    public int maxSum(int n) {
        // code here.
        
        if(n==0)
        return 0;
        int[]dp = new int[n+1];
        for(int i=1;i<=n;i++)
        {
            dp[i]=-1;
        }
        
     helper(n,dp);
     return dp[n];
    }
    
    public int helper(int n,int[]arr)
    {
        if(n==0)
        return 0;
        
        if(arr[n]!=-1)
        return arr[n];
        
        int temp=helper(n/2,arr)+helper(n/3,arr)+helper(n/4,arr);
        
        int ans=Math.max(n,temp);
        
        arr[n]=ans;
        
        return ans;
    }
}
