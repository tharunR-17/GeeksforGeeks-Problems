class Solution {
  public:
    vector<int> sortArray(vector<int> &arr, int A, int B, int C) {
        // code here
        int n = arr.size() ; 
        vector<int>ans ; 
        for(int i = 0 ; i<n ; i++){
            int x = arr[i] ; 
            int xq = x*x ; 
            int a = 1 ; 
            a = (A*xq)+(B*x)+C ; 
            ans.push_back(a) ; 
            
        }
        sort(ans.begin() , ans.end()) ; 
        return ans ; 
    }
};
