class Solution {
  public:
    vector<int> asciirange(string& s) {
        int n=s.size();
       
        vector<int>ans;
        for(char i='a'; i<='z'; i++){
            
            int mini=INT_MAX;
            int maxi=INT_MIN;
            for(int j=0; j<n; j++){
                if(s[j]==i){
                    mini=min(mini,j);
                    maxi=max(maxi,j);
                }
            }
           
              if (mini == INT_MAX || mini+1>=maxi) {
               
                continue;
            }
            int sum = 0;
            for (int j = mini+1; j < maxi; j++) {
                sum += s[j];
            }
            
            ans.push_back(sum);
        }
        
        return ans;
    }
};
