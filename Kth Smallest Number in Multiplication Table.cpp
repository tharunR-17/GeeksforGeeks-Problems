class Solution {
  public:
    int check(int t, int m, int n){
        int cnt=0;
        for(int i=1; i<=m; i++){
            cnt+=min(t/i, n);
        }
        return cnt;
    }
  
    int kthSmallest(int m, int n, int k) {
        // code here
        int lo=1, hi=m*n;
        while(lo<hi){
            int mid=lo+(hi-lo)/2;
            int tmp=check(mid, m, n);

            if(tmp<k) lo=mid+1;
            else hi=mid;
        }
        return lo;
    }
};
