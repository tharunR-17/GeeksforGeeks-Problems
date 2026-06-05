class Solution {
  public:
    virtual int calK(int n, int k){
      while(n>0){
        if(n==1) break;  
        if(n&1) return k*2;
        n>>=1;
      }
      
      return k/2;
    }
    
    virtual string lexicographicallySmallest(string &s, int k){
      string ans;
      
      int n=s.size();
      k=calK(n, k);
      
      
      if(n<=k) return "-1";
      
      stack<char> st;
      for(int i=0; i<n; i++){
        while((!st.empty()) && (k>0) && (s[i]<st.top())) { st.pop(); k--; }
        st.push(s[i]);
      }
      
      while((!st.empty()) && (k>0)){
        st.pop(); k--;  
      }
      
      while(!st.empty()){
        ans.push_back(st.top()); st.pop();  
      }
      
      reverse(ans.begin(), ans.end());
      return ans;
    }
};

