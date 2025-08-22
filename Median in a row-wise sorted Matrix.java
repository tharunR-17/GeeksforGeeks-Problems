class Solution {
    public int median(int[][] mat) {
        // code here
        List<Integer> list=new ArrayList<>();
        
        for(int i=0;i<mat.length;i++){
            for(int j=0;j<mat[0].length;j++){
                list.add(mat[i][j]);
            }
        }
        
        Collections.sort(list);
        
        return list.get(list.size()/2);
    }
}
