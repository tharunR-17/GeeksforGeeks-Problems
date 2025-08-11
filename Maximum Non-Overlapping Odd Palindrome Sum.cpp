class Solution {
  public:
    int maxSum(string &s) {
        // code here
       int n = s.size();
        if (n == 0) return 0;

        // Manacher odd-length radii d1[i]
        vector<int> d1(n);
        int l = 0, r = -1;
        for (int i = 0; i < n; ++i) {
            int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
            while (i - k >= 0 && i + k < n && s[i - k] == s[i + k]) ++k;
            d1[i] = k;
            if (i + k - 1 > r) {
                l = i - k + 1;
                r = i + k - 1;
            }
        }

        // best_end[pos] = max odd-palindrome length that ends at pos
        // best_start[pos] = max odd-palindrome length that starts at pos
        vector<int> best_end(n, 0), best_start(n, 0);

        // Record the largest palindrome for each center at its outer endpoints
        for (int c = 0; c < n; ++c) {
            int radius = d1[c];
            int len = 2 * radius - 1;
            int left = c - (radius - 1);
            int right = c + (radius - 1);
            best_end[right] = max(best_end[right], len);
            best_start[left] = max(best_start[left], len);
        }

        // Propagate inward: a palindrome of length L that ends at i+1 implies
        // an inner palindrome of length L-2 ends at i, etc.
        for (int i = n - 2; i >= 0; --i) {
            int cand = best_end[i + 1] - 2;
            if (cand > best_end[i]) best_end[i] = cand;
        }
        for (int i = 1; i < n; ++i) {
            int cand = best_start[i - 1] - 2;
            if (cand > best_start[i]) best_start[i] = cand;
        }

        // Build prefix max (best left palindrome up to i) and suffix max (best right palindrome from i)
        vector<int> left_max(n, 0), right_max(n, 0);
        left_max[0] = best_end[0];
        for (int i = 1; i < n; ++i) left_max[i] = max(left_max[i - 1], best_end[i]);
        right_max[n - 1] = best_start[n - 1];
        for (int i = n - 2; i >= 0; --i) right_max[i] = max(right_max[i + 1], best_start[i]);

        // Try all splits between i and i+1
        int ans = 0;
        for (int i = 0; i + 1 < n; ++i) {
            ans = max(ans, left_max[i] + right_max[i + 1]);
        }
        return ans;
        
    }
};
