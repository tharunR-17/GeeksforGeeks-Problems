class Solution {
   // public ArrayList<Integer> countBSTs(int[] arr) {
        // Code here
  static int[] computeCatalan(int n) {
        int[] cat = new int[n + 1];
        cat[0] = cat[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                cat[i] += cat[j] * cat[i - 1 - j];
            }
        }
        return cat;
    }

   
    public static ArrayList<Integer> countBSTs(int[] arr) {
        int n = arr.length;
        int[] catalan = computeCatalan(n);
        ArrayList<Integer> result = new ArrayList<>();

        int[] sorted = arr.clone();
        Arrays.sort(sorted);

        for (int i = 0; i < n; i++) {
            int idx = Arrays.binarySearch(sorted, arr[i]);
            int left = idx;
            int right = n - idx - 1;
            result.add(catalan[left] * catalan[right]);
        }

        return result;
    }
}
