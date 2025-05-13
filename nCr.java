class Solution {
    public int nCr(int n, int r) {
        // code here
        if(n<r)return 0;
        r=Math.min(r,n-r);
        long nCr=1;
        for(int i=1;i<=r;i++) {
            nCr*=(n-i+1);
            nCr/=i;
        }
        return (int) nCr;
    }
}
