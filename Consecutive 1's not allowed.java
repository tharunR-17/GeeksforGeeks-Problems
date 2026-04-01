class Solution {
    int countStrings(int n) {
       long[][] arr=new long[n][3];
       long pow=(long)Math.pow(2,n);
       arr[0][0]=pow/2;
       arr[0][1]=pow/2;
       arr[0][2]=pow;
       
       for(int i=1;i<n;i++){
           long zero=arr[i-1][0];
           long one=arr[i-1][1];
           
           arr[i][0]=(zero/2)+(one/2);
           arr[i][1]=(zero/2);
           
           arr[i][2]=arr[i][0]+arr[i][1];
       }
       return (int)arr[n-1][2];
    }
}
