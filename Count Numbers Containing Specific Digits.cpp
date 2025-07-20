class Solution {
  public:
    int countValid(int n, vector<int>& arr) {
        // code here
        unordered_set<int>s(arr.begin(),arr.end());
        
        // 10 - 99 = 90     ->2 digit
        // 100 - 999 = 900  ->3 digit
        
        int total = 9* pow(10,n-1);
        
        vector<int>allow;
        
        for(int i = 0 ; i < 10 ; i++){
            if(s.find(i) == s.end())
            allow.push_back(i);
            
            
        }
        
        int inValid = 0;
        int m = allow.size();
        
        for(auto it: allow){
            
            if(it == 0) continue;
            
            int count = 1;
            for(int i = 1 ; i <n ; i++){
                count *= m;
            }
            
            inValid += count;
        }
        
        return total - inValid;
        
        
    }
};
