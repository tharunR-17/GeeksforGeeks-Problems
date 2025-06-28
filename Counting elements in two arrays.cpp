class Solution {
  public:
    vector<int> countLessEq(vector<int>& a, vector<int>& b) {
        // code here
        int n = a.size();
        int m = b.size();
        vector<int>ans(n);
        int maxi = 0;
        sort(b.begin(),b.end());
        for(int i=0; i<n; i++)
        {
            int low=0,high=m-1;
            while(low<=high)
            {
                int mid = low + (high - low) / 2;
                if(b[mid]>a[i])
                {
                    high = mid-1;
                }
                else if(b[mid]<=a[i])
                {
                    low = mid+1;
                }
                
            }
                    ans[i] = low;
        }
        return ans;
    }
};

