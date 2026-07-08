class Solution {
  public:
    int row[4]={0,0,-1,1};
    int col[4]={-1,1,0,0};
    int n,m;
    void bfs(vector<vector<int>>& mat,queue<pair<int,int>>q,vector<vector<bool>>&visited){
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int nr=r+row[k];
                int nc=c+col[k];
                
                if(nr>=0 && nr<n && nc>=0 && nc<m && !visited[nr][nc] && mat[nr][nc]>=mat[r][c]){
                    visited[nr][nc]=1;
                    q.push({nr,nc});
                }
            }
        }
    }
    int countCoordinates(vector<vector<int>>& mat) {
        // code here
        n=mat.size();
        m=mat[0].size();
        queue<pair<int,int>>p,q;
        vector<vector<bool>>pvis(n,vector<bool>(m,0));
        vector<vector<bool>>qvis(n,vector<bool>(m,0));
        for(int i=0;i<n;i++){
            p.push({i,0});
            pvis[i][0]=1;
        }
        for(int j=0;j<m;j++){
            p.push({0,j});
            pvis[0][j]=1;
        }
        for(int i=0;i<n;i++){
            q.push({i,m-1});
            qvis[i][m-1]=1;
        }
        for(int j=0;j<m;j++){
            q.push({n-1,j});
            qvis[n-1][j]=1;
        }
        bfs(mat,p,pvis);
        bfs(mat,q,qvis);
        
        int cnt=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pvis[i][j] && qvis[i][j]){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
