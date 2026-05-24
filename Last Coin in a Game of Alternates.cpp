class Solution {
  public:
    int coin(vector<int>& arr) {
        // code here
        sort(arr.begin(), arr.end(), [](int &a, int &b){
            return a>b;
        });
        return arr[arr.size()-1];
    }
};

