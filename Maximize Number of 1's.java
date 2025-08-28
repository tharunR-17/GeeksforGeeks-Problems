class Solution {
    public int maxOnes(int arr[], int k) {
        int left = 0, right = 0;
        int zeroCount = 0;
        int maxLength = 0;

        while (right < arr.length) {
            if (arr[right] == 0) {
                zeroCount++;
            }

            while (zeroCount > k) {
                if (arr[left] == 0) {
                    zeroCount--;
                }
                left++;
            }

            maxLength = Math.max(maxLength, right - left + 1);
            right++;
        }

        return maxLength;
    }
}
