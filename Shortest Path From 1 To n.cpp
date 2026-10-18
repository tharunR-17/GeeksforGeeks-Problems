class Solution {
  public:
    int minimumStep(int n) {
        // code here
        int ans = 0;
        
        while(n){
            
            if(n%3)n--;
            else n/=3;
            ans++;
        }
        
        return ans-1;
    }
};
