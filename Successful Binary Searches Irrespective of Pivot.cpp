class Solution {
  public:
    int countAlwaysFound(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> prefixMax(n);
        vector<int> suffixMin(n);
        
        prefixMax[0] = arr[0];
        suffixMin[n-1] = arr[n-1];
        
        for (int i = 1; i < n; i++) {
            
            prefixMax[i] = max(arr[i], prefixMax[i-1]);
        }
        
        for (int i = n-2; i >= 0; i--) {
            
            suffixMin[i] = min(arr[i], suffixMin[i+1]);
        }
        
        int ans = 0;
        
        for (int i = 0; i < n; i++) {
            
            bool left = (i == 0) || (arr[i] > prefixMax[i-1]);
            bool right = (i == n-1) || (arr[i]< suffixMin[i+1]);
            
            if (left && right) {
                ans++;
            }
        }
        
        return ans;
    }
};

