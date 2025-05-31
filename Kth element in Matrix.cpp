class Solution {
  public:
    int check(int mid,vector<vector<int>>&matrix,int n,int m){
        int ans=0;
        
        for(int row=0;row<n;row++){
            ans+=upper_bound(matrix[row].begin(),matrix[row].end(),mid)-matrix[row].begin();
        }
        return ans;
    }
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        // code here
        // binary search 
        int n=matrix.size();
        int m=matrix[0].size();
        int l=matrix[0][0];
        int r=matrix[n-1][m-1];
        
        int ans=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            
            int cnt=check(mid,matrix,n,m);
            if(cnt>=k){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};
