class Solution {
    public int kthElement(int a[], int b[], int k) {
       int n1 = a.length;
      int n2 = b.length;
      int ret;
      if(n1 > n2) ret = fn(b,a,k);
      else ret = fn(a,b,k);
      return ret;
    }
    private int fn(int[] arr1, int[] arr2, int k){
        int n1 = arr1.length;
        int n2 = arr2.length;
        int left = k;
        int low = Math.max(0,k-n2);
        int high = Math.min(k,n1);
        while(low <= high){
            int mid1 = low + (high-low)/2;
            int mid2 = left-mid1;
            int l1 = mid1>0?arr1[mid1-1]:Integer.MIN_VALUE;
            int l2 = mid2>0?arr2[mid2-1]:Integer.MIN_VALUE;
            int r1 = mid1<n1?arr1[mid1]:Integer.MAX_VALUE;
            int r2 = mid2<n2?arr2[mid2]:Integer.MAX_VALUE;
            if(l1>r2) high = mid1-1;
            else if(l2>r1) low = mid1+1;
            else{
                return Math.max(l1,l2);
            }
        }
        return 0;
    }
}

