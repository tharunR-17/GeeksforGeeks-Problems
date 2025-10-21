class Solution {
    public ArrayList<Integer> topKFreq(int[] arr, int k) {
        // Most Optimal Approach
        ArrayList<Integer> ans = new ArrayList<>(); // store k frequents
        HashMap<Integer, Integer> freq = new HashMap<>(); // item, freq (frequency map)
        
        int n = arr.length;
        
        for(int i=0; i<n; i++){
            freq.put(arr[i], freq.getOrDefault(arr[i], 0)+1); // store the items along with their freq in map
        }
        
        @SuppressWarnings("unchecked")
        ArrayList<Integer>[] bucket = new ArrayList[n+1]; // index will be the frequency of item, list at index i will store the item itself with freq i
        
        for(int key : freq.keySet()){ // iterate over freq map
            int f = freq.get(key); // extract frequency
            if(bucket[f] == null) bucket[f] = new ArrayList<>(); // if not initialized yet => initalize it with new ArrayList
            bucket[f].add(key); // store the item in bucket[f] which has freq f
        }
        
        for(int i = n; i >= 0 && k > 0; i--) { // iterate from backward so that we will get the items with max freq .... decreasing
            if(bucket[i] != null) { // bucket contains valid freq at i
                Collections.sort(bucket[i], Collections.reverseOrder()); // larger number first (tie-breaker) => given in ques
                for(int num : bucket[i]) { // iterate over the items stored at freq f
                    ans.add(num); // add it to ans 
                    k--; // until ans contains k items
                    if(k == 0) break; // k items filled => exit the loop
                }
            }
        }
        return ans; // k frequent items 
    }
}
