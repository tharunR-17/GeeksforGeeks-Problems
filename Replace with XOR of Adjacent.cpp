class Solution {
  public:
    void replaceElements(vector<int>& arr) {
        // code here
        int curTotalXor = 0;
        int total = 0;
        int n = arr.size();
        for(int i=0;i<n-1;i++)
        {
            int x = curTotalXor^(arr[i]^arr[i+1]);
            arr[i] = x;
            curTotalXor ^= x;
        }
        arr[n-1] = curTotalXor;
    }
};
