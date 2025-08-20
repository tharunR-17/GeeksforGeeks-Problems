class Solution {
    public boolean searchMatrix(int[][] mat, int x) {
        // code here
        
        int n=mat.length;
        int m=mat[0].length;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==x) return true;
            }
        }
        
        return false;
    }
}
