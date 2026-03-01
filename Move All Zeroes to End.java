class Solution {
    void pushZerosToEnd(int[] arr) {
        // code here
        int x=0,n=arr.length;
        for(int num:arr) {
            if(num!=0) {
                arr[x]=num;
                x++;
            }
        }
        while((n-x)>0) {
            arr[x]=0;
            x++;
        }
    }
}
