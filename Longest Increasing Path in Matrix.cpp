class Solution {
  public:
   bool isvalid(vector<vector<int>> &matrix, int i, int j){
       return (i>=0 and j>=0 and i<matrix.size() and j<matrix[0].size());
   }
   int dirs[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
   int fun(vector<vector<int>> &mat,  vector<vector<int>>&dp, int i, int j){
       if(dp[i][j]!=0){return dp[i][j];}
       int ans=1;
       for(auto &b: dirs){
           int newi=i+b[0], newj=j+b[1];
           if(isvalid(mat, newi, newj) and mat[newi][newj]>mat[i][j]){
               ans=max(ans, 1+fun(mat, dp, newi, newj));
           }
       }
       return dp[i][j]=ans;
   }
  
    int longIncPath(vector<vector<int>> &matrix, int n, int m, int ans=0) {
       vector<vector<int>>dp(matrix.size(), vector<int>(matrix[0].size(), 0));
       for(int i=0; i<matrix.size(); i++){
           for(int j=0; j<matrix[0].size(); j++){
              ans=max(ans, fun(matrix, dp, i, j));
           }
       }
       return ans;
    }
};
