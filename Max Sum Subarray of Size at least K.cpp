class Solution {
  public:
    int maxSumWithK(vector<int>& arr, int k) {
        // code here
        int last=0;
        int sum=INT_MIN;
        int curr=0;
        int n=arr.size();
        int j=0;
        for(int i=0; i<n; i++){
            curr+=arr[i];
            if(i-j+1==k){
                sum=max(sum,curr);
            }
            else if(i-j+1>k){
                last+=arr[j];
                j++;
                if(last<0){
                  curr=curr-last;
                  last=0;
                }
                sum=max(sum,curr);  
            }
        }
       return sum; 
    }
};
