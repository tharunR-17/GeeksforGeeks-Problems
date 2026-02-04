class Solution {
    public int getLastMoment(int n, int left[], int right[]) {
      int maxLeft = 0;
        for (int pos : left) {
            maxLeft = Math.max(maxLeft, pos);
        }

        int maxRight = 0;
        for (int pos : right) {
            maxRight = Math.max(maxRight, n - pos);
        }

        return Math.max(maxLeft, maxRight);
    }
}
