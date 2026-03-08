class Solution {
    boolean pythagoreanTriplet(int[] arr) {
        // code here
        int n=arr.length;
        Arrays.sort(arr);
        for(int i=0;i<n-2;i++){
            if(arr[i]==arr[i+1]) continue;
            int a=arr[i];
            for(int j=i+1;j<n-1;j++){
                if(arr[j]==arr[j+1]) continue;
                int b=arr[j];
                for(int k=0;k<n;k++){
                    int c=arr[k];
                    if((a*a+b*b)==c*c || (b*b+c*c)==a*a || (a*a +c*c)==b*b){
                        return true;
                    }
                }
            }
        }
        return false;
    }
}
