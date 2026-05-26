class Solution {
  public:
    int minToggle(vector<int>& arr) 
    {
        int n=arr.size();
        int x=0;// no of zeroes
        int y=0;//no of ones
        vector<int>zero(n,0),one(n,0);
        for(int i=0;i<n;i++)
        {
            one[i]=y;
            if(arr[i]==1) 
            {
                y++;
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            zero[i]=x;
            if(arr[i]==0) 
            {
                x++;
            }
        }
        int mini=1e8;
        for(int i=0;i<n;i++)
        {
            mini=min(zero[i]+one[i],mini);
        }
        return mini;
    }
};
