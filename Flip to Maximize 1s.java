class Solution {
    int maxOnes(int[] arr) {
        // code here
        int n = arr.length;
        int maxOnesArr = Arrays.stream(arr).sum();
        
        int maxOnesSubArr = 0, sum = 0;
        
        for (int i = 0; i < n; i++) {
            sum = (arr[i] == 1) ? sum - 1 : sum + 1;
            
            if (sum < 0) sum = 0;
            else maxOnesSubArr = Math.max(maxOnesSubArr, sum);
        }
        
        return maxOnesArr + maxOnesSubArr;
    }
}
