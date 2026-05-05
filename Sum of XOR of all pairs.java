class Solution {
    public long sumXOR(int[] arr) {
        int n = arr.length;
        long total = 0;
        // Check each bit position (0–31)
        for (int i = 0; i < 32; i++) {
            long count1 = 0;
            for (int num : arr) {
                if ((num & (1 << i)) != 0) count1++;
            }
            long count0 = n - count1;
            total += count1 * count0 * (1L << i);
        }
        return total;
    }
}
