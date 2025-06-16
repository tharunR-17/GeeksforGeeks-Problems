class Solution {
  public:
    int minCost(vector<int>& heights, vector<int>& cost) {
        int n = heights.size();
        
        // Combine heights and costs into a single vector and sort
        vector<pair<int, int>> towers;
        for (int i = 0; i < n; i++) {
            towers.push_back({heights[i], cost[i]});
        }
        sort(towers.begin(), towers.end());
        
        // Precompute prefix sums for heights and costs
        vector<long long> prefixCost(n), prefixHeightCost(n);
        prefixCost[0] = towers[0].second;
        prefixHeightCost[0] = towers[0].first * towers[0].second;
        
        for (int i = 1; i < n; i++) {
            prefixCost[i] = prefixCost[i - 1] + towers[i].second;
            prefixHeightCost[i] = prefixHeightCost[i - 1] + towers[i].first * towers[i].second;
        }
        
        // Precompute suffix sums for costs and heights
        vector<long long> suffixCost(n), suffixHeightCost(n);
        suffixCost[n - 1] = towers[n - 1].second;
        suffixHeightCost[n - 1] = towers[n - 1].first * towers[n - 1].second;
        
        for (int i = n - 2; i >= 0; i--) {
            suffixCost[i] = suffixCost[i + 1] + towers[i].second;
            suffixHeightCost[i] = suffixHeightCost[i + 1] + towers[i].first * towers[i].second;
        }
        
        // Calculate the minimum cost for each tower as the target
        long long minCost = LLONG_MAX;
        for (int i = 0; i < n; i++) {
            long long targetHeight = towers[i].first;
            
            // Cost to adjust towers to the left of this target
            long long costLeft = (i > 0) 
                ? targetHeight * prefixCost[i - 1] - prefixHeightCost[i - 1]
                : 0;
            
            // Cost to adjust towers to the right of this target
            long long costRight = (i < n - 1) 
                ? suffixHeightCost[i + 1] - targetHeight * suffixCost[i + 1]
                : 0;
            
            // Total cost for this target
            minCost = min(minCost, costLeft + costRight);
        }
        
        return minCost;
    }
};
