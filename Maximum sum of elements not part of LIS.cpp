class Solution {
  public:
    int nonLisMaxSum(vector<int>& arr) {
       
        int n = arr.size();
        vector<int> lis_sum = arr;
        
        int sum = *min_element(begin(arr),end(arr));
        int len = 1;
        
        vector<int> dp(n,1);
        
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(arr[i] > arr[j]){
                    
                    if((1+dp[j]) > dp[i]){
                        lis_sum[i] = arr[i]+lis_sum[j];
                        dp[i] = 1+dp[j];
                    }
                    else if((1+dp[j]) == dp[i]){
                        if(arr[i] + lis_sum[j] < lis_sum[i]){
                            lis_sum[i] = arr[i]+lis_sum[j];
                        }
                    }
                    
                }
            }
            if(dp[i] > len){
                len = dp[i];
                sum = lis_sum[i];
            }
            else if(dp[i]==len){
                sum = min(sum,lis_sum[i]);
            }
        }
        
        return accumulate(begin(arr),end(arr),0) - sum;
    }
};
