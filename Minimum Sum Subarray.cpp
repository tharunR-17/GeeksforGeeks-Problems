class Solution {
  public:
    int minSubarraySum(vector<int> &arr) {
        // code here
        
        int ans = arr[0];
        int currSum = arr[0];
        int n = arr.size();
        
        for (int i = 1; i < n; i++) {
            
            currSum = min(arr[i], arr[i] + currSum);
            ans = min(ans, currSum);
        }
        
        return ans;
    }
};
