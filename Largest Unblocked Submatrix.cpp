class Solution {
  public:
    int largestArea(int n, int m, vector<vector<int>> &arr) {
        
        vector<int> rows = {0, n+1};
        vector<int> cols = {0, m+1};
        for(auto a: arr){
            rows.push_back(a[0]);
            cols.push_back(a[1]);
        }
        sort(rows.begin(), rows.end());
        sort(cols.begin(), cols.end());
        int diffR = 0;
        for(int i=1; i<rows.size(); i++){
            diffR = max(diffR, rows[i] - rows[i-1] - 1);
        }
        int diffC = 0;
        for(int i=1; i<cols.size(); i++){
            diffC = max(diffC, cols[i] - cols[i-1] - 1);
        }
        return diffR * diffC;
    }
};
