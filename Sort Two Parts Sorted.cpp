class Solution {
  public:
    void mergeTwoParts(vector<int>& arr) {
        int i = 1;
        while(i<arr.size() && arr[i-1] <= arr[i])i++;
        if(i == arr.size())return;
        vector<int>ans;
        int j = 0, a = i;
        while(j<a && i<arr.size()){
            if(arr[j] < arr[i]){
                ans.push_back(arr[j++]);
                continue;
            }
            ans.push_back(arr[i++]);
        }
        while(j<a){
            ans.push_back(arr[j++]);
        }
        while(i<arr.size()){
            ans.push_back(arr[i++]);
        }
        arr = ans;
    }
};
