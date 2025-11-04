class Solution {
    public static int minCost(int[] height) {
        // code here
       
        int n = height.length;
        if (n == 1) return 0;

        int prev2 = 0; 
        int prev1 = Math.abs(height[1] - height[0]);

        for (int i = 2; i < n; i++) {
            int jumpOne = prev1 + Math.abs(height[i] - height[i - 1]);
            int jumpTwo = prev2 + Math.abs(height[i] - height[i - 2]);
            int curr = Math.min(jumpOne, jumpTwo);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }

    public static void main(String[] args) {
        int[] height1 = {20, 30, 40, 20};
        System.out.println(minCost(height1)); 

        int[] height2 = {30, 20, 50, 10, 40};
        System.out.println(minCost(height2)); 
    }
}
