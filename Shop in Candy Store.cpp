class Solution {
  public:
    vector<int> minMaxCandy(vector<int>& prices, int k) {
        sort(prices.begin() , prices.end()) ;
        int n = prices.size() , mini = 0 , maxi = 0 ;
        int req = ceil(float(n)/float(k+1));
        for(int i = 0 ; i < req ; i ++){
            mini += prices[i] ;
            maxi += prices[n - i - 1] ;
        }
        vector<int>ans = {mini , maxi} ;
        return ans ;
    }
};
