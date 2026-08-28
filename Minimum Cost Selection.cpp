class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i,int n,int status,vector<vector<int>>& mat){
        if(status != -1 && dp[i][status] != INT_MAX){
            return dp[i][status];
        }
        if(i >= n){
            return dp[i][status] = 0;
        }
        if(status == 0){
            int a = solve(i+1,n,1,mat);
            int b = solve(i+1,n,2,mat);
            return dp[i][status] = min(a+mat[i][1],b+mat[i][2]);
        }
        else if(status == 1){
            int a = solve(i+1,n,0,mat);
            int b = solve(i+1,n,2,mat);
            return dp[i][status] = min(a+mat[i][0],b+mat[i][2]);
        }
        else if(status == 2){
            int a = solve(i+1,n,0,mat);
            int b = solve(i+1,n,1,mat);
            return dp[i][status] = min(a+mat[i][0],b+mat[i][1]);
        }
        else{
            int a = solve(i+1,n,0,mat);
            int b = solve(i+1,n,1,mat);
            int c = solve(i+1,n,2,mat);
            return min(a+mat[i][0],min(b+mat[i][1],c+mat[i][2]));
        }
    }
    int minCost(vector<vector<int>>& mat) {
        //very similar to ninja's training.
        //here we've to find minimum.
        int n = mat.size();
        dp.assign(n+2,vector<int>(4,INT_MAX));
        int i = 0;
        int status = -1;
        return solve(i,n,status,mat);
    }
};
