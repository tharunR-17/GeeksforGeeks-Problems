class Solution {
  public:
    int minFlips(string &s) {
        // code here
        bool flag1 = 0;
        bool flag2 = 1;
        int n = s.size();
        int ans1 = 0;
        int ans2 = 0;
        
        
        for(int i=0;i<n;i++){
            
            int c = s[i]-'0';
            if(c!=flag1)ans1++;
            if(c!=flag2)ans2++;
            flag1 = !flag1;
            flag2 = !flag2;
        }
        
        return min(ans1,ans2);
    }
};
