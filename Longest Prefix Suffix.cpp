class Solution {
public:
    int getLPSLength(string &s) {
        int n = s.size();
        vector<int> lps(n, 0); // Initialize LPS array
        int len = 0; // Length of the previous longest prefix suffix
        int i = 1;

        // Compute the LPS array
        while (i < n) {
            if (s[i] == s[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    // Fall back to the previous LPS position
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        // Return the last value of the LPS array
        return lps[n - 1];
    }
};
