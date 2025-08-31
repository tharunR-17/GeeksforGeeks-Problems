class Solution {
    public int maxWater(int arr[]) {
        int max =0;
        int i=0, j=arr.length-1;
        while(i<j){
            int k = (j-i)*(Math.min(arr[i], arr[j]));
            max=Math.max(max, k);
            if(arr[i]>arr[j]){
                j--;
            }
            else{
                i++;
            }
        }
        return max;
    }
}
