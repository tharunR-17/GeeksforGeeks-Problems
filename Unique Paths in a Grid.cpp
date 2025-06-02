class Solution {
  public:
    int solve(int i,int j,int r,int c,vector<vector<int>> &grid,vector<vector<int>> &dp){
        if(i==r-1 && j==c-1){
            return 1;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        int a =0 ;
        int b = 0;
        if(j<c-1 && grid[i][j+1]==0){
           a= solve(i,j+1,r,c,grid,dp);
        }
        
        if(i<r-1 && grid[i+1][j]==0){
           b = solve(i+1,j,r,c,grid,dp);
        }
        return dp[i][j] = a+b;
    }
    int uniquePaths(vector<vector<int>> &grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        if(grid[0][0]==1 || grid[rows-1][cols-1]==1) return 0;
        vector<vector<int>>dp(rows,vector<int>(cols,-1));
        return solve(0,0,rows,cols,grid,dp);
    }
};
