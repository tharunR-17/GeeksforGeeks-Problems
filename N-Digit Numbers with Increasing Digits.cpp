class Solution {
public:
    void solve(int i,vector<int> &ans,int n,int cnt,int &sum){
        cnt++;
        sum = sum*10+i;
        if(cnt == n){
            ans.push_back(sum);
            return ;
        }
        for(int j = i+1;j<=9;j++){
            solve(j,ans,n,cnt,sum);
            sum = sum/10;
        }
    }
    vector<int> increasingNumbers(int n) {
        vector<int> ans;
        if(n == 1){
            ans.push_back(0);
        }
        for(int i = 1;i<=9;i++){
            int cnt = 0;
            int sum = 0;
            solve(i,ans,n,cnt,sum);
        }
        return ans;
    }
};
