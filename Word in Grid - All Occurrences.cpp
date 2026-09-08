class Solution {
  public:
    vector<vector<int>> searchWord(vector<vector<char>> &mat, string &word) {
        // Code here
        int n  = mat.size()  , m = mat[0].size();
        auto isInside = [&](int a , int b){
            return a>=0 && b>=0 && a<n && b  <m;
        };
        int arr[] = {0 , 1 , 0 , -1 , -1 , 1 , 1 , -1 , 0};
        auto check = [&](int row , int col) -> bool{
            for(int dir  = 0 ;dir < 8 ; dir++){
                int i = row , j = col;
                int curr = 0;
                while(isInside(i , j)){
                    if(mat[i][j]!= word[curr++])break;
                    if(curr == word.size())return true;
                    i+=arr[dir] , j+=arr[dir+1];
                }
            }
            return false;
        };
        vector<vector<int>>ans;
        for(int i = 0 ;i<n ; i++){
            for(int j = 0 ;j<m ; j++){
                if(check(i , j))ans.push_back({i , j});
            }
        }
        return ans;
    }
};
