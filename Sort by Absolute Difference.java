class Solution {
    public void rearrange(int[] arr, int x) {
        //list of pairs: [value, original index]
        List<int[]> list = new ArrayList<>();
        for (int i = 0; i < arr.length; i++) {
            list.add(new int[]{arr[i], i});
        }

        // Custom Sorting 
        list.sort((a, b) -> {
            int diffA = Math.abs(a[0] - x);
            int diffB = Math.abs(b[0] - x);
            if (diffA != diffB) {
                return Integer.compare(diffA, diffB);
            } else {
                return Integer.compare(a[1], b[1]); // preserving original order
            }
        });

        // Copying sorted values back to arr
        for (int i = 0; i < arr.length; i++) {
            arr[i] = list.get(i)[0];
        }
    }
}
