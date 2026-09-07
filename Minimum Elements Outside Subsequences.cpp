class Solution {
  public:
    vector<vector<vector<int>>> dp;

    int minCount(vector<int>& arr) {
        int n = arr.size();

        dp.assign(n, vector<vector<int>>(n + 1, vector<int>(n + 1, -1)));

        return n - find(0, -1, -1, arr);
    }

    int find(int i, int inc, int dec, vector<int>& arr) {
        if (i == arr.size()) return 0;

        if (dp[i][inc + 1][dec + 1] != -1)
            return dp[i][inc + 1][dec + 1];

        int ans = find(i + 1, inc, dec, arr);

        if (inc == -1 || arr[i] > arr[inc]) {
            ans = max(ans, 1 + find(i + 1, i, dec, arr));
        }

        if (dec == -1 || arr[i] < arr[dec]) {
            ans = max(ans, 1 + find(i + 1, inc, i, arr));
        }

        return dp[i][inc + 1][dec + 1] = ans;
    }
};
