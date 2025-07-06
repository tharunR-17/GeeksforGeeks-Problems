class Solution {
  public:
    vector<int> topKSumPairs(vector<int> &a, vector<int> &b, int k) {
        int n = a.size();
        
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        priority_queue<pair<int, pair<int, int>>> pq;
        vector<int> ans(k);
        
        pq.push({a[n - 1] + b[n - 1], {n - 1, n - 1}});
        unordered_map<long long, int> mp;
        
        for(int u = 0; u < k; u++) {
            auto it = pq.top(); pq.pop();
            
            int i = it.second.first, j = it.second.second;
            
            if(mp.count(i * 1e9 + j) != 0) {
                u--;
                continue;
            }
            
            mp[i * 1e9 + j] = 1;
            ans[u] = it.first;
            
            
            if(i - 1 >= 0) pq.push({a[i - 1] + b[j], {i - 1, j}});
            if(j - 1 >= 0) pq.push({a[i] + b[j - 1], {i, j - 1}});
            
        }
        
        return ans;
        
    }
};
