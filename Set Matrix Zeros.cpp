class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &mat) {
        // code here
        unordered_map<int, bool> r, c;
        
        int n=mat.size();
        int m=mat[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    r[i]=true;
                    c[j]=true;
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]!=0){
                    if(r[i] || c[j])
                      mat[i][j]=0;
                }
            }
        }
        
        
        return;
    }
};

