class Solution {
    public boolean isProduct(int[] arr, long target) {
        // code here
        Arrays.sort(arr);
        int i=0,j=arr.length-1;
        while(i<j){
            if((long)arr[i]*arr[j]==target) return true;
            else if((long)arr[i]*arr[j]>target) j--;
            else i++;
        }
        return false;
    }
}
