class Solution {
  public:
    pair<int,int> BSIM(vector<vector<int>> &mat, int val){
        int n = mat.size();
        int m = mat[0].size();
        
        int low = 0;
        int high = n*m-1;
        
        while(low <= high){
            int mid = low + (high - low)/2;
            
            int row = mid/m;
            int col = mid%m;
            
            if(mat[row][col] == val){
                return pair<int,int>{row,col};
            }
            if(mat[row][col] < val){
                low = mid + 1;
            }
            else if(mat[row][col] > val){
                high = mid - 1;
            }
        }
        
        return pair<int,int>{-1,-1};
    }
    int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int x) {
        int n = mat1.size();
        int m = mat1[0].size();
        
        int cnt = 0;
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(mat1[i][j] >= x)goto end;
                pair<int,int> idx = BSIM(mat2,x-mat1[i][j]);
                if(idx.first == -1)continue;
                else cnt++;
            }
        }
        end:
        return cnt;
    }
};
