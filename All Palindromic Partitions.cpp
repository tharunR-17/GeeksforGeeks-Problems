class Solution {
    private:
    bool isPallindroem(const string &s, int start, int e){
        while(start< e){
            if(s[start]!= s[e]){
                return false;
            }
            start++;
            e--;
        }
        return true;
    }
    void getans(string &s, vector<string> &path, vector<vector<string>>&ans, int start){
        if(start>= s.length()){
            ans.push_back(path);
            return;
        }
        
        
        for (int e= start; e< s.length(); e++){
            if(isPallindroem(s, start, e)){
              path.push_back(s.substr(start, e-start+1));
              getans(s, path, ans, e+1);
             //Pop back
             path.pop_back();
                
            }
        }
    }
  public:
    vector<vector<string>> palinParts(string &s) {
        // code here
      vector<vector<string>> ans;
      vector<string> path;
      getans(s, path, ans, 0);
      return ans;
      
    }
};
