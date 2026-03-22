class Solution {
    public int orangesRot(int[][] mat) {
        // code here
        int count = 0;
        int m = mat.length;
        int n = mat[0].length;
        
        Queue<int[]> q = new LinkedList<>();
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j] == 2){
                    q.add(new int[]{i,j});
                }
            }
        }
        
        while(!q.isEmpty()){
            int size = q.size();
            boolean channge = false;
            for(int i=0;i<size;i++){
                int[] val = q.poll();
                int row = val[0];
                int col = val[1];
                
                if(col+1 < n && mat[row][col+1] == 1){
                    q.add(new int[]{row,col+1});
                    channge = true;
                    mat[row][col+1] = 2;
                }
                if(row+1 < m && mat[row+1][col] == 1){
                    q.add(new int[]{row+1,col});
                    channge = true;
                    mat[row+1][col] = 2;
                }
                if(col-1 >= 0 && mat[row][col-1] == 1){
                    q.add(new int[]{row,col-1});
                    channge = true;
                    mat[row][col-1] = 2;
                }
                if(row-1 >= 0 && mat[row-1][col] == 1){
                    q.add(new int[]{row-1,col});
                    channge = true;
                    mat[row-1][col] = 2;
                }
            }
            
            if (channge) count++;
            
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j] == 1){
                    return -1;
                }
            }
        }
        return count;
    }
}
