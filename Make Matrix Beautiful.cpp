class Solution {
  public:
    int balanceSums(vector<vector<int>>& mat) {
        // code here
        map<int,int>mp1;
        map<int,int>mp2;
        int target=-1;
        int sum =0;
        int n=mat.size();
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                mp1[i]+=mat[i][j];
                mp2[j]+=mat[i][j];
                target=max({target,mp1[i],mp2[j]});
                sum+=mat[i][j];
            }
        }
        return n*target-sum;
    }
};
