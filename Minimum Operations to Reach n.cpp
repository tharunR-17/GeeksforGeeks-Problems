class Solution {
  public:
    
    int minOperation(int n) {
        // code here
        if(n==0) return 0;
        int ope;
        if(n%2==0){ ope=minOperation(n/2) + 1;}
        else { ope= minOperation(n-1)+1;}
        return ope;
    }
};
