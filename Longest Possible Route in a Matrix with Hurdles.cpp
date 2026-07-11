class Solution {
  public:
    int dirX[4]={-1, 0, 1, 0};
    int dirY[4]={0, 1, 0, -1};
    
    virtual int svc(int i, int j, vector<vector<int>> &mat, int xd, int yd, vector<vector<bool>> &vis, int &lg){
      if(i==xd && j==yd) return 0;    
      vis[i][j]=true;
      
      int ans = -100000000;
      
      for(int k=0; k<4; k++){
        int ni=i+dirX[k];  
        int nj=j+dirY[k];
        
        if(ni<0 || nj<0 || (ni>=(mat.size())) || (nj>=(mat[0].size())) || (mat[ni][nj]==0) || (vis[ni][nj])) continue;
        
        ans=max(ans, 1 + svc(ni, nj, mat, xd, yd, vis, lg));
        lg=max(lg, ans);
        
      }
      
      vis[i][j]=false;
      return ans;
    }
    
    virtual int longestPath(vector<vector<int>>& mat, int xs, int ys, int xd, int yd){
        
      int n=mat.size();
      int m=mat[0].size();
      
      if(mat[xs][ys]==0 || mat[xd][yd]==0) return -1;
      
      int lg=-1;
      vector<vector<bool>> vis(n+1, vector<bool>(m+1, false));
      
      int nt = svc(xs, ys, mat, xd, yd, vis, lg);
      return max(lg, nt);
    }
};
