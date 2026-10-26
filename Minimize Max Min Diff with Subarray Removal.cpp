class Solution {
  public:
    int minDiff(int k, vector<int> &arr) {
        // code here
        
        int n = arr.size();
        vector<int> leftMin(n);
        vector<int> leftMax(n);
        vector<int> rightMin(n);
        vector<int> rightMax(n);
        
        leftMin[0] = arr[0];
        leftMax[0] = arr[0];
        rightMin[n-1] = arr[n-1];
        rightMax[n-1] = arr[n-1];
        
        for (int i = 1; i < n; i++) {
            
            leftMin[i] = min(leftMin[i-1], arr[i]);
            leftMax[i] = max(leftMax[i-1], arr[i]);
        }
        
        for (int i = n-2; i >= 0; i--) {
            
            rightMin[i] = min(rightMin[i+1], arr[i]);
            rightMax[i] = max(rightMax[i+1], arr[i]);
        }
        
        int ans = INT_MAX;
        
        for (int i = 0; i+k <= n; i++) {
            
            int mi = INT_MAX;
            int mx = INT_MIN;
            
            if (i > 0) {
                mi = leftMin[i-1];
                mx = leftMax[i-1];
            }
            
            if (i + k < n) {
                mi = min(mi, rightMin[i+k]);
                mx = max(mx, rightMax[i+k]);
            }
            
            ans = min(ans, mx - mi);
        }
        
        return ans;
    }
};
