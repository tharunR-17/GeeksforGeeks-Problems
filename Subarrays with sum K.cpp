class Solution {
  public:
    int cntSubarrays(vector<int> &arr, int k) {
        unordered_map<int, int> map;
        int ans = 0,sum = 0;
        
        for(int i = 0;i<arr.size();i++){
            sum += arr[i];
            
            if(sum==k) ans++;
            
            if(map.count(sum-k)){
                ans += map[sum-k];
            }
            
            map[sum]++;
        }
        
        return ans;
    }
};
