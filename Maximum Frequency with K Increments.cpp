class Solution {
  public:
    int maxFrequency(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        sort(arr.begin(),arr.end());
        vector<long long >prefix(n);
        prefix[0]=arr[0];
        for(int i=1;i<n;i++){
            prefix[i]=arr[i]+prefix[i-1];
            
            
        }
        int maxi=0;
        for(int i=0;i<n;i++){
            if(i-1>=0 && arr[i]==arr[i-1]){
                continue;
                
            }
            int index=lower_bound(arr.begin(),arr.end(),arr[i]+1)-arr.begin();
            int l=0;
            int r=index-1;
            while(l<=r){
                int mid=l+(r-l)/2;
                int sum=prefix[index-1]-((mid-1)>=0?prefix[mid-1]:0);
                int size=(index-mid)*arr[i];
                int total=size-sum;
                if(total<=k){
                    maxi=max(maxi,index-mid);
                    r=mid-1;
                }
                else{
                    l=mid+1;
                }
                
            }
            
            
        }
        return maxi;
    }
};
