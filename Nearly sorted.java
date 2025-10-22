class Solution {
    public void nearlySorted(int[] arr, int k) {
        // code here
        int n = arr.length;
        int[] sortedArr = new int[n];
        int c = 0;
        
        // step 1: create a min heap
        PriorityQueue<Integer> pq = new PriorityQueue<>(
            (a,b) -> a-b
            );
            
            
        // step 2: traverse the array and add every element 
        // into the min heap
        // Since it is given that every element is atmost k places
        // away from it's sorted position, we remove the front 
        // element of the queue and put it in it's sorted place 
        // in sortedArr. 
        
        for(int i = 0 ;i<n;i++){
            
            pq.offer(arr[i]);
            if(pq.size() > k){
                sortedArr[c++] = pq.poll();
            }
        }
        
        // Step 3: copy the rest elements in min heap to the sortedArr
        
        while(!pq.isEmpty()){
            
            sortedArr[c++] = pq.poll();
        }
        
        // Step 4: copy the elements in sortedArr to arr
        for(int i = 0;i<n;i++){
            arr[i] = sortedArr[i];
        }
    }
}

