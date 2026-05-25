class Solution {
  public:
    bool checkElements(int start, int end, vector<int> &arr) {
        // code here
        int n = arr.size();
        sort(arr.begin(), arr.end());
        
        int x = -1;
        int y = -1;
        
        for(int i=0; i<n; i++){
            if(arr[i] == start)
                x = i;
            if(arr[i] == end)
                y = i;
        }
        
        if(x == -1 || y == -1)
            return false;
        
        
        for(int j = x; j<y; j++){
            if(arr[j+1] == arr[j] +1)
                continue;
            else
                return false;
        }
        return true;
    }
};
