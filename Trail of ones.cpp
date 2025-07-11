class Solution {
  public:
    int solve(int n, int prev){
        if(n==0){
            return 1;
        }
        int a=0;
        if(prev==0){
            
            a=solve(n-1,1);
        }
        else{
            prev=0;
        }
        a+=solve(n-1,0);
        return a;
    }
    int countConsec(int n) {
        // code here
        return pow(2,n)-solve(n,0);
    }
};

