class Solution {
    ArrayList<Integer> intersection(int[] a, int[] b) {
        // code here
        ArrayList<Integer> result = new ArrayList<>();
        
        int i = 0, j = 0;
        
        while (i < a.length && j < b.length) {
            if (a[i] == b[j]) {
                if (result.isEmpty() || result.get(result.size() - 1) != a[i]) {
                    result.add(a[i]);
                }
                i++;
                j++;
            } 
            else if (a[i] < b[j]) {
                i++;
            } 
            else {
                j++;
            }
        }
        
        return result;
    }
}
