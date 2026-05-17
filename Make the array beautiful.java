class Solution {
    List<Integer> makeBeautiful(int[] arr) {
        int size = arr.length;
        Deque<Integer> dq = new ArrayDeque<>();
        
        for(int i = 0; i < size; i++) {
            // Same sign
            if( dq.isEmpty() || (dq.peekLast() >= 0 && arr[i] >= 0) || (dq.peekLast() < 0 && arr[i] < 0) ) {
                dq.addLast(arr[i]);
            }
            // Different sign
            else {
                dq.pollLast();
            }
            
        }
        
        return new ArrayList<>(dq);
    }
}
