class Solution {
    static ArrayList<Integer> kthLargest(int[] arr, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        int n = arr.length;
        ArrayList<Integer> ans = new ArrayList<>();
        
        for(int i=0; i<n; i++){
            pq.add(arr[i]);
            if(pq.size() == k){
                ans.add(pq.peek());
            } else if(pq.size() < k){
                ans.add(-1);
            } else {
                pq.poll();
                ans.add(pq.peek());
            }
        }
        
        return ans;
        
        
    }
}
