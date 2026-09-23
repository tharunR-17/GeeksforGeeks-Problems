class Solution {
  public:
    int formPyramid(vector<int>& arr) {
        // code here
        
        /*
        
        we find maximum peak point to reduce cost
        [1, 2, 3, ,4, 2, 1]
        
        [1, 2, 3, 4, 1, 0] answer is this
        wo make left , right array to store peek we try to make peek every ith element
        
        left = [1, 2, 3, 4, 2, 1]
        right = [1, 2, 3, 3, 2, 1]
        
        try to make maximum pyramid
        so Peek = min(left[i], right[i])
        
        assume you pick = 3
        that time you need to find cost
        this is one pattern 
        left side = [1, 2, 3]
        right side = [2, 1] in sabka sum chiya bss huma
        
        left side = n * (n + 1) / 2 sum of n natural number means max peek = 3 n = 3
        righ side = n * (n - 1) / 2 sum of n-1 natural number means max peak = 3 = 3-1 n = 2
        
        totalPyarmidSum = leftSide + rightSide
        totalPyarmidSum = n * (n + 1) / 2 + n * (n - 1) / 2;
        
        totalPyarmidSum = n * n; 
        so the final ansewr is 
        answerOfCost = totalArraySum - totalPyarmidSum
        */
        
        int totalSum = accumulate(begin(arr), end(arr), 0);
        
        int n = arr.size();
        vector<int> left(n);
        vector<int> right(n);
        
        left[0] = 1;
        right[n-1] = 1;
        
        for (int i = 1; i < n; ++i) {
            
            left[i] = min(left[i-1] + 1, arr[i]);
        }
        
        for (int i = n-2; i >= 0; --i) {
            
            right[i] = min(right[i+1] +1 , arr[i]);
        }
        
        
        int maxPyramidPeek = 0;
        
        for (int i = 0; i < n; i++) {
            
            int peek = min(left[i], right[i]);
            maxPyramidPeek = max(maxPyramidPeek, peek);
        }
        
        int pyramidTotalSum =maxPyramidPeek * maxPyramidPeek;
        
        int cost = totalSum - pyramidTotalSum;
        
        
        return cost;
    }
};
