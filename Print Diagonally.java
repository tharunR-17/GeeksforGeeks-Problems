class Solution {
    static ArrayList<Integer> diagView(int mat[][]) {
        // code here
        int n = mat.length;
        int cnt = n + n - 1;
        int row = 0;
        int col = 0;
        ArrayList<Integer> result = new ArrayList<>();
        while(cnt > 0){
            int colIterator = Math.min(col , n - 1);
            int rowIterator = Math.min(row , n - 1);
            
            while(colIterator >= 0 && rowIterator < n){
                result.add(mat[rowIterator][colIterator]);
                rowIterator++;
                colIterator--;
            }
            col++;
            if(col >= n){
                row++;
            }
            cnt--;
        }
        return result;
    }
}
