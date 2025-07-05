class Solution {
  public:
    int maxSum(vector<int> &arr) {
        int res=0;
        for(int i=0;i<arr.size()-1;i++)
        {
            res=max(res,arr[i]+arr[i+1]);
        }
        return res;
        
    }
};
