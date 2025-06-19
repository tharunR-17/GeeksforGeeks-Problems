class Solution {
  public:
    string caseSort(string& s) {
        string p = s;
        sort(p.begin(), p.end());
        int i = 0;
        for(auto& ch : s){
            if(isupper(ch)){
                ch = p[i++];
            }
        }
        for(auto& ch : s){
            if(islower(ch)){
                ch = p[i++];
            }
        }
        return s;
    }
};
