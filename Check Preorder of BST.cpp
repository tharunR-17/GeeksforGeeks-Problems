class Solution {
  public:
    void buildBST(int n,int & min,int& max,int& preIndex,vector<int>&arr){
        if(preIndex>=n){
            return;
        }
        if(min<=arr[preIndex]&&arr[preIndex]<=max){
            int rootData=arr[preIndex];
            preIndex++;
            buildBST(n,min,rootData,preIndex,arr);
            buildBST(n,rootData,max,preIndex,arr);
        }
    }
    bool canRepresentBST(vector<int> &arr) {
        // code here
        int max=INT_MAX;
        int min=INT_MIN;
        int preIndex=0;
        int n=arr.size();
        buildBST(n,min,max,preIndex,arr);
        return preIndex==n;
    }
};
