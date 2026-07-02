#include <vector>

class Solution {
public:
    bool divisibleByK(std::vector<int>& arr, int k) {
        int n = arr.size();
        if (n >= k) return true;
        
        std::vector<bool> dp(k, false);
        
        for (int num : arr) {
            int rem = num % k;
            if (rem == 0) return true;
            
            std::vector<bool> next_dp = dp;
            next_dp[rem] = true;
            
            for (int i = 0; i < k; ++i) {
                if (dp[i]) {
                    int new_rem = (i + rem) % k;
                    if (new_rem == 0) return true;
                    next_dp[new_rem] = true;
                }
            }
            
            dp = std::move(next_dp);
        }
        
        return dp[0];
    }
};
