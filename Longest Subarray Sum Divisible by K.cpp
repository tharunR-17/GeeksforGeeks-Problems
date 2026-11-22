class Solution {
  public:
    int longestSubarrayDivK(vector<int>& arr, int k) {
        unordered_map<int, int> first;
        long long sum = 0;
        int maxLen = 0;
        first[0] = -1;
        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];
            int rem = ((sum % k) + k) % k;
            if (first.count(rem)) {
                maxLen = max(maxLen, i - first[rem]);
            } else {
                first[rem] = i;
            }
        }
        return maxLen;
    }
};
