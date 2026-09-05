class Solution {
  public:
    int longestSubseq(vector<int>& a) {
        // code here
        int n=a.size();
        unordered_map<int,int>mp;
        int maxi=0,b,c;
        for(auto i:a)
        {
            b=i-1,c=i+1;
            mp[i]=max(mp[b],mp[c])+1;
            maxi=max(maxi,mp[i]);
        }
        return maxi;
        
    }
};
