class Solution {
  public:
    int maxArea(vector<int> &height) {
        // code here
        int maxA = 0;
        int i = 0;
        int j = height.size()-1;
        int leftMax = 0;
        int rightMax = 0;
        
        while (i < j) {
            
            leftMax = max(leftMax, height[i]);
            rightMax = max(rightMax, height[j]);
            
            int val = min(leftMax, rightMax);
            int len = j-i-1;
            
            maxA = max(maxA, val * len);
            
            if (height[i] < height[j]) {
                i++;
            } else {
                j--;
            }
        }
        
        return maxA;
    }
};
