class Solution {
  public:
    int maxPackages(vector<int>& arr, int tt) {
        int n=arr.size(),i=0,j=0,cs=0,maxi=0;
        if(tt>=n) return accumulate(begin(arr),end(arr),0);
        
        while(j<tt) cs+=arr[j++],maxi=max(maxi,cs);
        while(j<n){
            cs+=arr[j]-arr[i];
            maxi=max(maxi,cs);
            i++,j++;
        }
        
        return maxi;
    }
};

