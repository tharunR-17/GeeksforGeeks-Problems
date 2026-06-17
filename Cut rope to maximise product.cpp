class Solution {
  public:
    int maxProduct(int n) {
        // code here
        if(n==2){
            return 1;
        }
        int prod=INT_MIN;
        for(int i=2;i<n;i++){
            int rem=n%i,quo=n/i;
            int curr_prod=1;
            for(int j=0;j<i;j++){
                curr_prod*=quo+(rem!=0);
                if(rem!=0){
                    rem--;
                }
            }
            prod=max(prod,curr_prod);
        }
        return prod;
    }
};
