class Solution {
  public:
    long long mode=1000000007;
    
    virtual long long power(long long a, long long b){
      long long ans=1LL;
      
      while(b>0){
        if(b&1) ans=(ans*a)%mode;
        a=(a*a)%mode;
        b>>=1;
      }
      
      return ans%mode;
    }
    
    virtual long long modInv(long long x){
      return (power(x, mode-2))%mode;    
    }
    
    
    virtual int computeValue(int n){
      long long ans=1LL;
      
      for(int i=1; i<=n; i++){
        ans = (ans * (2LL*n - i + 1))%mode;
        ans = (ans * modInv(i))%mode;
      }
      
      
      return (int)(ans);
    }
};

