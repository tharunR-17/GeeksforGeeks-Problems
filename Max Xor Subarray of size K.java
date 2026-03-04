class Solution {
    public int maxSubarrayXOR(int[] arr, int k) {
        // code here
        int x=0;
        for(int i=0;i<k;i++){
            x^=arr[i];
        }
        int m=x;
        for(int i=k;i<arr.length;i++){
            x^=arr[i];
            x^=arr[i-k];
            m=Math.max(m,x);
        }
        return m;
    }
}
