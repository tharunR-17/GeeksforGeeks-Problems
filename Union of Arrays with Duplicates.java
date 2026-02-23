class Solution {
    public static ArrayList<Integer> findUnion(int[] a, int[] b) {
        // code here
        HashSet<Integer> set = new HashSet<>();
        
        // Step 2: Add elements of array a
        for (int num : a) {
            set.add(num);
        }
        
        // Step 3: Add elements of array b
        for (int num : b) {
            set.add(num);
        }
        
        // Step 4: Convert set to ArrayList
        return new ArrayList<>(set);
    }
}
