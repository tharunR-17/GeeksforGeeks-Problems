class Solution {
  public:
    int findMax(int n, vector<int>& a, vector<int>& b, vector<int>& k) {
        // code here
        int m = a.size() ;
        vector<int> arr(n+1 , 0) ;
        
        for(int i=0 ; i<m ; i++){
            int start = a[i] , end = b[i] , add = k[i] ;
            
            arr[start] += add ;
            arr[end+1] -=add ;
        }
        
        int res = 0 , curr = 0;
        
        for(int i=0 ; i<n ; i++){
            curr += arr[i] ;
            res = max(res , curr) ;
        }
        return res ;
    }
};
