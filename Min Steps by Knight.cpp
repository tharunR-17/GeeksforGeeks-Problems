class Solution {
  public:
    int m;
    int row[8] = {-2,-2,-1,1,2,2,1,-1};
    int col[8] = {-1,1,2,2,1,-1,-2,-2};
    
    bool check(int i,int j){
        return i>=0 && j>=0 && i<m && j<m;
    }
    
    int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int n) {
        // Code here
        m=n;
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>visited(n,vector<int>(n,0));
        q.push({{knightPos[0]-1,knightPos[1]-1},0});
        int t1 = targetPos[0]-1;
        int t2 = targetPos[1]-1;
        visited[knightPos[0]-1][knightPos[1]-1]=1;
        
        while(!q.empty()){
            
            auto a = q.front();
            q.pop();
            int i = a.first.first;
            int j = a.first.second;
            int ans = a.second;
            if(i==t1 && j==t2)return ans;
            
            for(int k=0;k<8;k++){
                
                if(check(i+row[k],j+col[k]) && !visited[i+row[k]][j+col[k]]){
                    q.push({{i+row[k],j+col[k]},ans+1});
                    visited[i+row[k]][j+col[k]]=1;
                }
            }
        }
        
        
    }
};
