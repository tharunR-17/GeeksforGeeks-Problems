class Solution {
  public:
    int maxPeopleDefeated(int p) {
        int ans=0,c=p;
        for(int i=1;i<sqrt(c);i++){
            if(i*i<=p){
                ans++;
                p=p-i*i;
            }
            else
                break;
        }
        return ans;
    }
};
