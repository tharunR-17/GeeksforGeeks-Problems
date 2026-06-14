class Solution {
  public:
    vector<int> exitPoint(vector<vector<int>>& mat) {
        // code here
        int dx=0,dy=1;
        int n=mat.size();
        int m=mat[0].size();
        
        int i=0,j=0;
        while(i>=0 && j>=0 && i<n && j<m){
            if(mat[i][j]==1){
                if(dy==1 && dx==0){
                    dx=1;dy=0;
                }
                else if(dy==0 && dx==1){
                    dy=-1;dx=0;
                }
                else if(dy==-1 && dx==0){
                    dx=-1;dy=0;
                }
                else if(dy==0 && dx==-1){
                    dy=1;dx=0;
                }
                mat[i][j]=0;
            }
            i+=dx;
            j+=dy;
        }
        if(j<0) return {i,j+1};
        else if(i>=n) return {i-1,j};
        else if(j>=m) return {i,j-1};
        else if(i<0) return {i+1,j};
    }
};
