class Solution {
    public int kthSmallest(int[][] mat, int k) {
        // code here
        PriorityQueue<Integer> pq = new PriorityQueue<>(Comparator.reverseOrder());
        
        for(int[] row : mat){
            for(int num : row){
                pq.add(num);
            }
            while(pq.size() > k) pq.poll();
        }
        // for(int i = 0;i<k-1;i++) pq.poll();
        
        return pq.poll();
    }
}
