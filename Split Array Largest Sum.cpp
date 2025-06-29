class Solution {
  public:
    bool possible(int mid,vector<int> &arr,int k){
        int cnt=1,sum=0; 
        for(int i=0;i<arr.size();i++){
            if(sum+arr[i]<=mid)sum+=arr[i];
            else {
                sum=arr[i];
                cnt++;
            }
        }
        return cnt<=k;
    }
    
    int splitArray(vector<int>& arr, int k) {
        int l=*max_element(arr.begin(),arr.end());
        int r=accumulate(arr.begin(),arr.end(),0);
        int ans=0;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(possible(mid,arr,k)){
                ans=mid;
                r=mid-1;
            }else l=mid+1;
        }
        return ans;
    }
};
