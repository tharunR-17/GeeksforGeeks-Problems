class Solution {
    public int maxWater(int arr[]) {
        // code here
        int n=arr.length,totalWater=0;
        int arr1[]=new int[n];
        int arr2[]=new int[n];
        arr1[0]=arr[0];
        for(int i=1;i<n;i++) {
            arr1[i]=Math.max(arr[i],arr1[i-1]);
        }
        arr2[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--) {
            arr2[i]=Math.max(arr[i],arr2[i+1]);
        }
        for (int i = 0; i < n; i++) {
            totalWater += Math.min(arr1[i], arr2[i]) - arr[i];
        }

        return totalWater;
    }
}
