class Solution {
  public:
    int dominantPairs(vector<int> &arr) {
        // Code here
        vector<int>lower, upper;
        int n = arr.size();
        for(int i = 0;i<arr.size();i++){
            if(i<(n>>1)){
                lower.push_back(arr[i]);
                continue;
            }
            upper.push_back(arr[i]);
        }
        sort(lower.begin(), lower.end());
        int cnt = 0;
        for(auto it : upper){
            int ind = lower_bound(lower.begin(), lower.end(), 5*it) - lower.begin();
            cnt+=(lower.size() - ind);
        }
        return cnt;
    }
};
