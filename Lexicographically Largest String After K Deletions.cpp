class Solution {
  public:
    string maxSubseq(string& s, int k) {
        // code here
        int n=s.size();
        string ans;
        int count=0;
        for(char &ch:s){
            while(!ans.empty() && ans.back()<ch && count<k){
                ans.pop_back();
                count++;
            }
            ans.push_back(ch);
        }
        while(!ans.empty() && count<k){
            ans.pop_back();
            count++;
        }
        return ans;
    }
};
