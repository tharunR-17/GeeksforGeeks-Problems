class Solution {
  public:
    vector<int> findMajority(vector<int>& arr) {
        // Code here
        int c1=-1, c2=-1;
        int v1=0, v2=0;
        
        for(auto z: arr){
            if(c1==z)
              v1++;
            else if(c2==z)
              v2++;
            else if(v1==0){
                c1= z;
                v1++;
            }
            else if(v2==0){
                c2= z;
                v2++;
            }
            else{
                v1--;
                v2--;
            }
        }
        
        v1=0;
        v2=0;
        
        for(auto z: arr){
            if(z==c1)
              v1++;
            else if(z==c2)
              v2++;
             
        }
        
        vector<int> ans;
        int n= arr.size();
        
        if(v1>(n/3))
          ans.push_back(c1);
        if(v2>(n/3))
          ans.push_back(c2);
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};
